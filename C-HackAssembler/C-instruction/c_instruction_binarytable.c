#include "c_instruction.h"

binarytable_t* binarytable_init() {

    // instruction_string table
    binarytable_t* BinaryTable = MallocExit(sizeof(*BinaryTable));
    BinaryTable->capacity = 35;
    BinaryTable->size     = 0;

    // Bucket list
    bucket_t** BucketList = BinaryTable->BucketList = Calloc(BinaryTable->capacity, sizeof(*BucketList));
    if (BucketList == NULL) { // free BinaryTable if error
        free(BinaryTable);
        exit(EXIT_FAILURE);
    }

    return BinaryTable;
}

void BinaryTable_destroy(binarytable_t *BinaryTable) {

    // check if null
    if (BinaryTable == NULL) return;

    // Bucket list items destroy
    for (size_t i = 0; i < BinaryTable->capacity; i++) {
        bucket_t *current = BinaryTable->BucketList[i];

        while (current) {
            bucket_t *next = current->next;
            free(current->instruction_string);              // maybe unneccessary if I don't have to malloc a string
            free(current);
            current = next;
        }
    }

    // Bucket list destroy
    free(BinaryTable->BucketList);

    // instruction_string table destroy
    free(BinaryTable);
}


char binarytable_set(binarytable_t *BinaryTable, const char* instruction_string, unsigned short instruction_binary) {
    
    // get hashkey
    unsigned short key = binarytable_hashcode(BinaryTable, instruction_string);

    // save the current bucket that will be worked on
    bucket_t *currBucket = BinaryTable->BucketList[key];

    // go to furthest collission bucket, check if key already exists
    while (currBucket) {
        if (strcmp(currBucket->instruction_string, instruction_string) == 0) {
            currBucket->instruction_binary = instruction_binary;
            return -1;
        }
        currBucket = currBucket->next;
    }

    // key not in instruction_string table, alloc new 
    bucket_t *bucket = CallocExit(1, sizeof(*bucket));
    bucket->instruction_string = strdup(instruction_string);
    bucket->instruction_binary = strdup(instruction_binary);
    bucket->next               = BinaryTable->BucketList[key];

    //shift the open space to the front
    BinaryTable->BucketList[key] = bucket;
    BinaryTable->size++;

    return 0;
}

char binarytable_get(binarytable_t *BinaryTable, const char* instruction_string, unsigned short *out_instruction_binary) {
    bucket_t *currBucket = BinaryTable->BucketList[binarytable_hashcode(BinaryTable, instruction_string)];

    while (currBucket) {
        if (strcmp(currBucket->instruction_string, instruction_string) == 0) {
            *out_instruction_binary = currBucket->instruction_binary;
            return 0;
        }
        currBucket = currBucket->next;
    }
    return -1;
}



//// helper functions
unsigned short  binarytable_hashcode(binarytable_t *BinaryTable, const char* instruction_string) {
    unsigned long hash = 5381; // starting prime
    int c;

    while ((c = *instruction_string++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return (unsigned short)(hash % BinaryTable->capacity);
}

// malloc wrapper

void* Malloc(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
    }
    return ptr;
}

void* Calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if ( ptr == NULL ) {
        perror("Malloc error");
    }
    return ptr;
}

void* CallocExit(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if ( ptr == NULL ) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* MallocExit(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
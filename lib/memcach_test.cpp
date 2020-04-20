#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libmemcached/memcached.h>

int main(void) {
  memcached_st *memc;
  memcached_server_st *servers = NULL;
  memcached_return rc;
  const char* server_list = "localhost:11211";
  const char* key= "yeke";
  const char* value= "24";
  char* retval = NULL;
  size_t len = 0;
  time_t expire = 0;
  uint32_t flags = 0;
 
 
  memc = memcached_create(NULL);
  servers = memcached_servers_parse(server_list);
  rc = memcached_server_push(memc, servers);
  memcached_server_list_free(servers);  
  if(rc == MEMCACHED_SUCCESS) {
    printf("added server successfully\n");
  } else {
    printf("couldn't add server: %s\n", memcached_strerror(memc, rc));
  }

  rc = memcached_set(memc, key, strlen(key), value, strlen(value), expire, flags);
  if(rc == MEMCACHED_SUCCESS) {
    printf("key stored successfully\n");
  } else {
    printf("couldn't store key: %s\n", memcached_strerror(memc, rc));
  }

  retval = memcached_get(memc, key, strlen(key), &len, &flags, &rc);
  if(rc == MEMCACHED_SUCCESS) {
    printf("key got successfully\n");
    printf("value: %s\n", retval);
  } else {
    printf("couldn't get key: %s\n", memcached_strerror(memc, rc));
  }
  free(retval); 

/*
  rc = memcached_delete(memc, key, strlen(key), expire);
  if(rc == MEMCACHED_SUCCESS) {
    printf("key deleted successfully\n");
  } else {
    printf("couldn't delete key: %s\n", memcached_strerror(memc, rc));
  }
*/

  char sKey[256]="ye ke";
  retval = memcached_get(memc, sKey, strlen(sKey), &len, &flags, &rc);

  if(rc == MEMCACHED_SUCCESS) {
    printf("key got successfully\n");
    printf("value: %s\n", retval);
  } else if(rc == MEMCACHED_NOTFOUND) {  
    printf("couldn't get key (not found): %s\n", memcached_strerror(memc, rc));
  } else if(rc == MEMCACHED_FAILURE) {  
    printf("couldn't get key (failure): %s\n", memcached_strerror(memc, rc));
  }
  free(retval);

  rc = memcached_set(memc, sKey, strlen(sKey), "", strlen(value), expire, flags);
  if(rc == MEMCACHED_SUCCESS) {
    printf("key stored successfully\n");
  } else {
    printf("couldn't store key: %s\n", memcached_strerror(memc, rc));
  }

  retval = memcached_get(memc, key, strlen(key), &len, &flags, &rc);
  if(rc == MEMCACHED_SUCCESS) {
    printf("key got successfully\n");
    printf("value: %s\n", retval);
  } else if(rc == MEMCACHED_NOTFOUND) {  
    printf("couldn't get key (not found): %s\n", memcached_strerror(memc, rc));
  } else if(rc == MEMCACHED_FAILURE) {  
    printf("couldn't get key (failure): %s\n", memcached_strerror(memc, rc));
  }
  free(retval); 

  retval = memcached_get(memc, sKey, strlen(sKey), &len, &flags, &rc);

  if(rc == MEMCACHED_SUCCESS) {
    printf("key got successfully\n");
    printf("value: %s\n", retval);
  } else if(rc == MEMCACHED_NOTFOUND) {
    printf("couldn't get key (not found): %s\n", memcached_strerror(memc, rc));
  } else if(rc == MEMCACHED_FAILURE) {
    printf("couldn't get key (failure): %s\n", memcached_strerror(memc, rc));
  }
  free(retval);
  
  memcached_free(memc);
  return 0;
}


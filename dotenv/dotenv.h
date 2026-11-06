#ifndef __DOTENV_DOTENV_H__
#define __DOTENV_DOTENV_H__

/**
 * @param path Can be a directory containing a file named .env, or the path of the env file itself
 * @param overwrite Existing variables will be overwritten
 * @return 0 on success, -1 if can't open the file
 */
int env_load(const char* path, int overwrite);

#endif


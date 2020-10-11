// Copyright 2018 Your Name <your_email>

#include <chrono>
#include <ctime>
#include <iostream>

int main() {
  int32_t* array02mb = new int32_t[48 * 1024];
  int32_t* array1mb = new int32_t[256 * 1024];
  int32_t* array2mb = new int32_t[512 * 1024];
  int32_t* array4mb = new int32_t[1024 * 1024];

  int32_t* array8mb = new int32_t[2048 * 1024];
  int32_t* array13mb = new int32_t[3456 * 1024];
  for (size_t k = 0; k < 48 * 1024; k++) {
    array02mb[k] = rand();
  }
  for (size_t k = 0; k < 256 * 1024; k++) {
    array1mb[k] = rand();
  }
  for (size_t k = 0; k < 512 * 1024; k++) {
    array2mb[k] = rand();
  }
  for (size_t k = 0; k < 1024 * 1024; k++) {
    array4mb[k] = rand();
  }
  for (size_t k = 0; k < 2048 * 1024; k++) {
    array8mb[k] = rand();
  }
  for (size_t k = 0; k < 3456 * 1024; k++) {
    array13mb[k] = rand();
  }
  int32_t f = 0;

  // 192 Кб
  //ВПЕРЕД

  for (size_t k = 0; k < 48 * 1024; k += 16) {
    f = array02mb[k];
  }
  std::chrono::system_clock::time_point start =
      std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 48 * 1024; k += 16) {
      f = array02mb[k];
    }
  }
  std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
  std::cout << "array 0.2 mb "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД

  for (int k = 49151; k >= 0; k -= 16) {
    f = array02mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 49152; k >= 0; k -= 16) {
      f = array02mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 0.2 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // СЛУЧАЙНО
  for (size_t k = 0; k < 48 * 1024; k += 16) {
    f = array02mb[(rand() % 3072) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 48 * 1024; k += 16) {
      f = array02mb[(rand() % 3072) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 0.2 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // 1Mb
  //ВПЕРЕД
  for (size_t k = 0; k < 262144; k += 16) {
    f = array1mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 262144; k += 16) {
      f = array1mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 1 mb forward "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД
  for (int k = 262143; k >= 0; k -= 16) {
    f = array1mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 262143; k >= 0; k -= 16) {
      f = array1mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 1 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // СЛУЧАЙНО
  for (size_t k = 0; k < 262144; k += 16) {
    f = array1mb[(rand() % 16384) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 262144; k += 16) {
      f = array1mb[(rand() % 16384) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 1 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // 2Mb
  //ВПЕРЕД
  for (size_t k = 0; k < 524288; k += 16) {
    f = array2mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 524288; k += 16) {
      f = array2mb[k];
    }
  }

  end = std::chrono::system_clock::now();
  std::cout << "array 2 mb forward "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД
  for (int k = 524287; k >= 0; k -= 16) {
    f = array2mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 524287; k >= 0; k -= 16) {
      f = array2mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 2 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // СЛУЧАЙНО
  for (size_t k = 0; k < 524288; k += 16) {
    f = array2mb[(rand() % 32768) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 524288; k += 16) {
      f = array2mb[(rand() % 32768) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 2 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // 4Mb
  //ВПЕРЕД
  for (size_t k = 0; k < 1048576; k += 16) {
    f = array4mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 1048576; k += 16) {
      f = array4mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 4 mb forward "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД
  for (int k = 1048575; k >= 0; k -= 16) {
    f = array4mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 1048575; k >= 0; k -= 16) {
      f = array4mb[k];
    }
  }

  end = std::chrono::system_clock::now();
  std::cout << "array 4 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // СЛУЧАЙНО
  for (size_t k = 0; k < 1048576; k += 16) {
    f = array4mb[(rand() % 65536) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 1048576; k += 16) {
      f = array4mb[(rand() % 65536) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 4 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // 8Mb
  //ВПЕРЕД
  for (size_t k = 0; k < 2097152; k += 16) {
    f = array8mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 2097152; k += 16) {
      f = array8mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 8 mb forward "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД
  for (int k = 2097151; k >= 0; k -= 16) {
    f = array8mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 2097151; k >= 0; k -= 16) {
      f = array8mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 8 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;
  // СЛУЧАЙНО
  for (size_t k = 0; k < 2097152; k += 16) {
    f = array8mb[(rand() % 131072) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 2097152; k += 16) {
      f = array8mb[(rand() % 131072) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 8 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  // 13Mb
  //ВПЕРЕД
  for (size_t k = 0; k < 3538944; k += 16) {
    f = array13mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 3538944; k += 16) {
      f = array13mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 13 mb forward "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //НАЗАД
  for (int k = 3538943; k >= 0; k -= 16) {
    f = array13mb[k];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (int k = 3538943; k >= 0; k -= 16) {
      f = array13mb[k];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 13 mb back "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  //СЛУЧАЙНО

  for (size_t k = 0; k < 3538944; k += 16) {
    f = array13mb[(rand() % 221184) * 16];
  }
  start = std::chrono::system_clock::now();
  for (size_t r = 0; r < 1000; r++) {
    for (size_t k = 0; k < 3538944; k += 16) {
      f = array13mb[(rand() % 221184) * 16];
    }
  }
  end = std::chrono::system_clock::now();
  std::cout << "array 13 mb random "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  std::cout << f;
}

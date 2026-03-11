# Завдання 4.6: realloc з NULL та розміром 0

### Спостереження
1. `realloc(NULL, size)` працює ідентично до `malloc(size)`.
2. `realloc(ptr, 0)` звільняє пам'ять і повертає `NULL` у більшості сучасних систем, виконуючи роль `free()`.
<img width="776" height="73" alt="zvd4_6" src="https://github.com/user-attachments/assets/ad0a66fe-2f8c-4740-b854-1deed18a418c" />

    int x = 7;  
    int y;       
    int *p = &x;  
    y = *p + 3;
    printf("El valor de x: %d\n", x);
    printf("El valor de y: %d\n", y);
    printf("El valor apuntado por p: %d\n", *p);
    printf("La dirección de x: %p\n", (void*)&x);
    printf("La dirección almacenada en p: %p\n", (void*)p);
    return 0;
}

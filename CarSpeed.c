// m_x -> Periodo Máximo
// i_f -> Início da Frenagem
// m_c_p -> periodo máximo da constante
// c_p -> Periodo da constante
// m_a -> Acenaeraçao Máxima
// a_i -> Aceleraçâo instantanea
// ac -> Aceleração
// f -> Fremagem
// m_f -> Maior Frenagem

#include <stdio.h>

int main() {
    int i, a = 1, m_x = 1, i_f = 0, m_c_p = 1;
    int a_i = 0;
    float m_a = 0.0, ac;
    int c_p = 1;
    int v[60];

    printf("==============================================================\n");

    for(i = 0; i < 60; i++) {
        printf("Determine a velocidade em m/s no tempo de %d segundos do veículo: ", i);
        scanf("%d", &v[i]);
    }

    for(i = 1; i < 60; i++) {
        if(v[i] >= v[i-1]) {
            a++;
            if(a > m_x) {
                m_x = a;
            }
        } else {
            a = 1; 
        }
    }
    
    printf("\n==============================================================\n");
    
    printf("\nO maior período sem diminuir a velocidade foi nos %d segundos\n", m_x);

    int m_f = 0;
    for(i = 0; i < 59; i++) {
        int f = v[i] - v[i+1];
        if(f > m_f) {
            m_f = f;
            i_f = i;
        }
    }
    
    printf("\n==============================================================\n");
    
    printf("\nA maior frenagem foi nos %d segundos\n", i_f);

    for(i = 0; i < 59; i++) {
        ac = v[i+1] - v[i];
        if(ac > m_a) {
            m_a = ac;
            a_i = i;
        }
    }
    
    printf("\n==============================================================\n");
    
    printf("\nA maior aceleração positiva foi de %.2f m/s² aos %d segundos\n", m_a, a_i);

    for(i = 1; i < 60; i++) {
        if(v[i] == v[i-1]) {
            c_p++;
            if(c_p > m_c_p) {
                m_c_p = c_p;
            }
        } else {
            c_p = 1;
        }
    }
    
    printf("\n==============================================================\n");
    
    printf("\nO maior período com velocidade constante foi nos %d segundos\n", m_c_p);
    
    printf("\n==============================================================\n");

    return 0;
}

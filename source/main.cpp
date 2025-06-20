// Colisão com os cantos da tela
// inclui a biblioteca allegro
#include <allegro.h>

int main()
{
    // BUFFER, serve para não desenhar-mos diretamente na tela e assim
    // evitando o efeito de pisca-pisca
    BITMAP *buffer = NULL;

    // inicializa a posição do quadrado
    int x = 0;
    int y = 0;

    // dimensao do quadrado
    // variáveis constantes nunca mudam durante a execução do programa
    const int tamanho = 100;

    // inicializa a biblioteca, sempre deve ser chamada
    allegro_init();

    // profundidade de cores, 32 é melhor no Win7
    set_color_depth(32);

    // permite a leitura do teclado
    install_keyboard();

    // cria a janela com a largura 640 e altura 480 pixels
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    // Criando BUFFER, ela é um ponteiro para um BITMAP
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    // Laço principal
    while(!key[KEY_ESC]) // o programa deve rodar enquanto não pressionar a tecla ESC
    {
        if(key[KEY_UP]) // se pressionou para cima
        {
            y--; // move o quadrado para cima
        }
        if(key[KEY_DOWN]) // se pressionou para baixo
        {
            y++; // move o quadrado para baixo
        }
        if (key[KEY_LEFT]) // se pressionou para esquerda
        {
            x--; // move o quadrado para a esquerda
        }
        if (key[KEY_RIGHT]) // se pressionou para direita
        {
            x++; // move o quadrado para a direita
        }

        // limpa o buffer para um novo desenho (pinta tudo de preto)
        clear(buffer);

        // pinta o quadrado no buffer
        rectfill(buffer, x, y, x + tamanho, y + tamanho, makecol(255, 0, 0));

        // imprimimos as coordenadas x e y no buffer para o usuário ver na tela
        textprintf_ex(buffer, font, 10, 10, makecol(255, 0, 0), -1, "Variavel X: %d", x);
        textprintf_ex(buffer, font, 10, 20, makecol(255, 0, 0), -1, "Variavel Y: %d", y);

        // imprime o buffer na tela
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        // essa função faz o allegro esperar um pouco antes de voltar para o while
        rest(10);
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();
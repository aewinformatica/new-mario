#include "video.h"

void inicializar_video(int largura, int altura) {
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, largura, altura, 0, 0);
}

void limpar_tela() {
    clear(screen);
}

void desenhar_sprite(BITMAP* sprite, int x, int y) {
    draw_sprite(screen, sprite, x, y);
}

void fechar_video() {
    allegro_exit();
}

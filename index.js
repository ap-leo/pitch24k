document.addEventListener('DOMContentLoaded', (event) => {
    const botaoSobre = document.getElementById("botaoSobre");
    const sobre = document.getElementById('sobre');
    const video = document.getElementById('background-video');

    aux = 0;
    botaoSobre.addEventListener('click', () => {
        if (aux == 0){
            sobre.style.opacity = '1';
            video.style.filter = 'brightness(0.2)';
            aux = !aux;
            return;
        }
        sobre.style.opacity = '0';
        video.style.filter = 'brightness(0.7)';
        aux = !aux;
    });
});

document.addEventListener('DOMContentLoaded', () => {
    const scrollingWrapper = document.querySelector('.scrolling-wrapper');
    const setaEsquerda = document.querySelector('.setap1');
    const setaDireita = document.querySelector('.setap2');

    const imgWidth = scrollingWrapper.querySelector('img').offsetWidth;
    const margin = parseInt(window.getComputedStyle(scrollingWrapper.querySelector('img')).marginRight);

    const scrollAmount = imgWidth + margin; // Ajuste a quantidade de rolagem para uma imagem

    setaEsquerda.addEventListener('click', () => {
        scrollingWrapper.scrollBy({
            left: -scrollAmount,
            behavior: 'smooth'
        });
    });

    setaDireita.addEventListener('click', () => {
        scrollingWrapper.scrollBy({
            left: scrollAmount,
            behavior: 'smooth'
        });
    });
});

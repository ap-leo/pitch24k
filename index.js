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

    const scrollAmount = imgWidth + margin; // rolagem para uma imagem

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


function calcularDiasFaltando(dataFutura) {
    // Cria um objeto Date para a data futura
    const dataFuturaObj = new Date(dataFutura);

    // Cria um objeto Date para a data atual
    const hoje = new Date();

    // Calcula a diferença em milissegundos
    const diferencaMs = dataFuturaObj - hoje;

    // Converte a diferença de milissegundos para dias
    const umDiaMs = 24 * 60 * 60 * 1000;
    const diasFaltando = Math.ceil(diferencaMs / umDiaMs);

    return diasFaltando;
}

const dataFutura = '2024-09-11';
var aux = calcularDiasFaltando(dataFutura)
const dias = 100 - aux;
var bat = document.getElementById('bateria');

bateria.style.height = dias + '%';

const dia = document.getElementById('dias');
dia.textContent = 'Faltam ' + aux + ' dias';

const passada = document.getElementById('passada')
const video = document.getElementById('video')
const grade = document.getElementById('grade')
const fotos = document.querySelector('.grid-item');
const voltar = document.getElementById('voltar')

var aux = 1;
var local = 'p';
const gridItems = document.querySelectorAll('.grid-item');

gridItems.forEach((item, index) => {
    item.style.backgroundImage = `url(imgs/${local}${aux}.jpeg)`;
    item.style.backgroundSize = 'cover';
    item.style.backgroundPosition = 'center';
    aux++;
});



passada.addEventListener('click', function(){
    video.classList.add('fade-out');
    setTimeout(function() {
        video.style.display = 'none';
        grade.style.display = 'grid';
        voltar.style.display = 'flex';
    }, 1000); 
})

voltar.addEventListener('click', function(){
    grade.style.opacity = '0';
    setTimeout(function() {
        grade.style.display = 'none';
        video.style.display = 'flex';
        voltar.style.display = 'none';
        video.style.opacity = 1;
    }, 1000); 
})
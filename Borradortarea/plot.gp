set xlabel 'N'; set ylabel 'Diferencia %'
set title 'Diferencias porcetuales obtenidas hasta N=400'
set term pdf; set out "fig.pdf"
plot 'datos.txt' using 1:2 w l t 'diferencia % 1:3', 'datos.txt' using 1:3 w l t 'diferencia % 2:3'
inteiro = gets.to_i    
puts inteiro  
banknotes = [100, 50, 20, 10, 5, 2, 1]
aux = inteiro

banknotes.each do |div|
	printf("%d nota(s) de R$ %d,00\n",  aux/div, div )
	aux = aux % div
end
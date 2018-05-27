def PERCENTUAL(a,b)
	return ((b - a) / a)  * 100
end

def main()
	i = 1
	while true
		begin
			# a=gets.to_f
			# b=gets.to_f

			line=gets
			ar=line.split()
			a=ar[0].to_f
			b=ar[1].to_f

			if a == 0 and b == 0
				break
			end
		rescue
			break
		end

		print("Projeto %d:\n" % (i) )
		print("Percentual dos juros da aplicacao: %.2f %%\n\n" % PERCENTUAL(a,b) )

		i = i+1
	end
end

main()
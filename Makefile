all : 
	make -C ./mandatory all

bonus : 
	make -C ./bonus all

clean :
	make -C ./mandatory clean
	make -C ./bonus clean

fclean : clean
	make -C ./mandatory fclean
	make -C ./bonus fclean

re : clean all

.PHONY : bonus
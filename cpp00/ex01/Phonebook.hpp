#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <stdlib.h>


# define MAX_CONTACTS 8

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();


		int		Add();
		int		Search();
	private:
		Contact	contacts[MAX_CONTACTS];
		short	_index;
		
		// Helpers
		void	printContacts();
		bool	isPrintableStr(std::string& str);
		bool	isAllDigitStr(std::string& str);
		bool	hasOnlySpaces(std::string& str);
};

// Utils
std::string		readInput(const std::string& Message);
void			displayContactInfo(Contact& contact);

// Prints

void			printIndividualContact(Contact contact, int index);
void			printInfo(std::string str);

void			printHeader(void);
void			printErrorEOF(void);
void			printErrorMessage(const std::string& eMessage);

#endif

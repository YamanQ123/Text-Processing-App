#include <fstream>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <conio.h>


using namespace std;

// functions used to open and close file
fstream open_file();
fstream open_file(string &file);
fstream open_file_again(string& file);
void close_file(fstream& x);


vector<string> file2lines(fstream& x); // this function returns vector of lines of file 
// the following two function are used in find and replace part
int return_ascii(char& a);  // only changes upper case letters to lower case letters


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// the following three functions used in substring search (boyre moore's function) ////////////

void alphabet_fill(int right[], string pat); // used to fill array of 26 numbers ..relative to each letter ..
//to get its (RIGHTMOST) index in the pattern we look for int the text

int hit(string &text, string &pat, int& index, int alphabet[]);  // hit is the function that handles the comparison of last letter in pattern 
// with letter in text at [index] .. and uses alphabet[] in the process

void find_and_replace(string &text, string &pat, int alphabet[], string &replace); //this function uses hit() function ... to take pattern and the replace word
// to locate the pattern and replace it with new word

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void reset_handle(char &condition); // just a function containing some cout lines for the output

void output_in_txtfile(vector<string> x); // this function takes the name of output file and vector of lines to put in the text file 

void waleed_function();  // this function only encloses the find and replace() functionality with the user input requests 

vector<string> text2words(fstream& x); // this function returns vector of string of all words in the text

string word_modifier(string x); // this function makes sure that words from text only of lower case with no commas or anything else

void groupOf_find_and_replace(vector<string> wrong, vector<string > right, fstream& x);// this function takes group of wrong words
// and group of right words to replace them










class node

{
	string data;

	node * next;

public:

	node() { data = ""; next = NULL; }

	node(string d) :data(d), next(NULL) {}

	string getData() { return data; }

	void setData(string d) { data = d; }

	node * getNext() { return next; }

	void setNext(node * n) { next = n; }

	friend class list;
};
class list

{
	node * chain;

public:

	list();
	list(string d);
	list(string a[], int size);
	void add(string d);
	node * find(string d)
	{
		node *p = chain;
		while (p != NULL)
		{
			if (p->data == d) return p;

			p = p->next;
		}

		return NULL;

	}
	void remove(string d) // remove node with value d

	{ //special case if it is empty list

		if (chain == NULL) return;

		if (chain->data == d) //special case removing 1st node

		{
			node * temp = chain;

			chain = chain->next;

			delete temp;
		}

		else {
			node * p = chain;

			if (p->next == NULL) return; //value not found

			while (p->next->data != d) //stop at the node before

			{
				p = p->next;

				if (p->next == NULL) return;
			}//value not found

			node * p2 = p->next; //normal remove as in figure

			p->next = p2->next;

			delete p2;

		}

	}
	void del() {

		if (chain != NULL)

		{
			node * p = chain;

			while (p->next != NULL)

			{

				node * temp = p->next;

				delete p;

				p = temp;

			}

			chain = NULL;

		}
	}
	void printall()

	{
		int o = size() - 1;
		node *p = chain;

		while (p != NULL)

		{
			cout << p->getData() << endl;

			p = p->getNext(); // or p=p->next;

		}
		cout << endl;

	}
	string toString() {

		string s = "";
		s += "( ";
		int o = size() - 1;
		node *p = chain;

		while (p != NULL)

		{
			if (p->getNext() != NULL) {
				s += p->getData() += ", ";
			}
			else s += p->getData() += " ";
			p = p->getNext(); // or p=p->next;

		}

		s += ")\n";
		return s;

	}
	void reverse() {
		int s = size();
		if (s <= 1)
			return;
		string * a = new string[s];
		node* p = chain;
		for (int i = 0; i < s; i++) {
			a[i] = p->data;
			p = p->next;
		}
		del();
		for (int i = 0; i < s; i++) {
			add(a[i]);
		}
		delete[] a;
		a = NULL;


	}


	bool isEmpyt() {
		//check if chain points to null
		//if then the list is empty
		if (chain == NULL)
			return true;
		//else it's not
		else
			return false;
	}

	int size() {
		if (chain == NULL)
			return 0;
		node * p = chain;
		int s = 1;
		while (p->next != NULL)

		{
			s++;
			p = p->next;


		}

		return s;
	}

	string* toArray() {
		int s = size();
		string *a = new string[s];
		node*p = chain;
		for (int i = 0; i < s; i++) {
			a[i] = p->data;
			p = p->next;
		}
		return a;
	}

};
list::list() : chain(NULL) {}
list::list(string d) {

	chain = new node(d);


}
list::list(string a[], int size) {
	for (int i = size - 1; i >= 0; i--)
		add(a[i]);
}
void list::add(string item) // add at front

{

	node * temp = new node(item);

	temp->setNext(chain); // or temp->next=chain

	chain = temp;


}
class TST {
private:
	class Node {
	private:
		char c;
		Node * left, *mid, *right;
		string  val;
	public:
		Node* getMid() { return mid; }
		Node* getLeft() { return left; }
		Node* getRight() { return right; }
		string getVal() { return val; }
		char getChar() { return c; }
		void setChar(char character) { c = character; }
		void setMid(Node* ptr) { mid = ptr; }
		void setLeft(Node* ptr) { left = ptr; }
		void setRight(Node* ptr) { right = ptr; }
		void setVal(string value) { val = value; }

	};
public:
	string get(string key) {
		Node* x = get(root, key, 0);
		//if (x == NULL) return NULL;
		return x->getVal();
	}
	bool contains(string key) {
		Node* x = get(root, key, 0);
		if (x->getVal() == "")
			return false;
		return true;
	}
	void put(string key, string val) {
		root = put(root, key, val, 0);
	}
	list* autoComplete(string key) {
		list* l = new list();
		Node* x = get(root, key, 0);
		x = x->getMid();
		collect(x, l);
		l->reverse();
		return l;
	}
	string prefix(string key) {
		string pre = "";
		int d = 0;
		prefix(root, key, d, pre);
		return pre;
	}

private:
	Node* root;
	Node* get(Node* x, string key, int d) {
		if (x == NULL) return new Node();
		char c = key[d];
		if (c < x->getChar()) return get(x->getLeft(), key, d);
		else if (c > x->getChar())return get(x->getRight(), key, d);
		else if (d < key.length() - 1)
			return get(x->getMid(), key, d + 1);
		else return x;
	}

	Node* put(Node* x, string key, string val, int d) {
		char c = key[d];

		if (x == NULL) { x = new Node(); x->setChar(c); }

		if (c < x->getChar()) { x->setLeft(put(x->getLeft(), key, val, d)); }
		else if (c > x->getChar()) { x->setRight(put(x->getRight(), key, val, d)); }
		else if (d < key.length() - 1)
			x->setMid(put(x->getMid(), key, val, d + 1));
		else x->setVal(val);
		return x;
	}
	void collect(Node* x, list* l) {
		if (x == NULL)return;
		if (x->getVal() != "") {
			l->add(x->getVal());
		}
		collect(x->getLeft(), l);
		collect(x->getMid(), l);
		collect(x->getRight(), l);
	}
	void prefix(Node* x, string key, int d, string & pre) {
		if (x == NULL) return;
		char c = key[d];
		if (c < x->getChar())  prefix(x->getLeft(), key, d, pre);
		else if (c > x->getChar())prefix(x->getRight(), key, d, pre);
		else if (d < key.length() - 1) {
			pre += c;
			prefix(x->getMid(), key, d + 1, pre);
		}
	}
};
string reverse(string s) {
	string rs = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		rs += s[i];
	}
	return rs;
}
//identicalLetters: takes to strings and return the number of identical letters

//return true if the string contains the char
bool haveChar(char c, string s) {
	for (int i = 0; i < s.length(); i++) {
		if (c == s[i])
			return true;
	}
	return false;
}
int charI(char c) {
	return int(c) - 97;
}
int identicalLettersNo(string a, string b) {
	int no = 0;
	int offset = 97;
	int visitedChar[26];
	for (int i = 0; i < 26; i++)
		visitedChar[i] = 0;

	for (int i = 0; i < a.length(); i++) {
		char c = a[i];
		if (visitedChar[charI(c)] < 2) {
			if (haveChar(c, b)) {
				no++;
				visitedChar[charI(c)]++;
			}
		}
	}
	return no;
}
int wordsAlligenment(string a, string b) {
	string x;
	string y;
	int n = 0;
	int r = 0;
	if (a.length() <= b.length()) { n = a.length(); x = a; y = b; }
	else { n = b.length(); x = b; y = a; }
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == y[j]) {
			//if (i == 0)r += 3;
			//else
			r++;
		}
		j++;
	}
	j = y.length() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (x[i] == y[j]) {
			//if (i == n-1)r += 10;
			//else
			r++;
		}
		j--;
	}
	return r;
}



///////////////////////////////////////////////////////////////////////
///////////////////Main Functions//////////////////////////////////////
TST* Dict;
TST *DictR;
bool SpellCheck(string word) {
	return Dict->contains(word);
}

list* AutoComplete(string key) {
	return Dict->autoComplete(key);
}

list* WordSuggetion(string word) {
	list* suggestions = new list();
	if (!SpellCheck(word)) {
		int max = 0;
		int no = 0;
		int wordlength = word.length();
		TST* checked = new TST();
		string pre = Dict->prefix(word);
		string prer = DictR->prefix(reverse(word));
		list* autoCompleted = Dict->autoComplete(pre);
		list* autoCompletedr = DictR->autoComplete(prer);
		int sizeAuto = autoCompleted->size();
		int sizeAutor = autoCompletedr->size();
		string* autoArray = autoCompleted->toArray();
		string* autoArrayr = autoCompletedr->toArray();
		for (int i = 0; i < sizeAuto; i++) {
			if (wordlength - 1 <= autoArray[i].length() <= wordlength + 1) {
				no = identicalLettersNo(word, autoArray[i]) + wordsAlligenment(word, autoArray[i]);
				string s = autoArray[i];
				no += wordsAlligenment(s, word);
				if (no > max) {
					max = no;
					suggestions->del();
					suggestions->add(autoArray[i]);

					checked->put(s, s);
				}
				else if (no == max) {
					suggestions->add(autoArray[i]);
					checked->put(s, s);
				}
			}

		}
		for (int i = 0; i < sizeAutor; i++) {
			if (!checked->contains(autoArrayr[i])) {
				if (wordlength - 1 <= autoArrayr[i].length() <= wordlength + 1) {
					no = identicalLettersNo(word, autoArrayr[i]);
					string s = autoArrayr[i];
					no += wordsAlligenment(s, word);
					if (no > max) {
						max = no;
						suggestions->del();
						suggestions->add(autoArrayr[i]);

					}
					else if (no == max) {
						suggestions->add(autoArrayr[i]);

					}
				}
			}

		}
	}
	return suggestions;
}
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


//choice1 is the choice of checking text file and replacing faults
void choice1_handle(fstream& x) {
	if (!x.is_open()) {
		cout << "failed" << endl;
		return;
	}
	vector<string> wrong;
	vector<string> right;
	char con;
	char c;
	string temp;
	do {
		cout << endl << "do you want to use Auto Complete ? y/n" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			cout << endl << "##################################################################" << endl;
			//AutoComplete("she")->toString();

			string kk;
			cout << endl << "please enter the word required for autoComplete : " << endl;
			cin >> kk;
			cout << AutoComplete(kk)->toString();
			cout << endl << "##################################################################" << endl;
		}
		cout << "please write wrong word to remove  : " << endl;
		cin >> temp;
		wrong.push_back(temp);

		cout << "please write right word instead  : " << endl;
		cin >> temp;
		right.push_back(temp);

		reset_handle(con);
	} while (con == 'y' || con == 'Y');
	if (!x.is_open()) {
		cout << "failed" << endl;
		return;
	}
	groupOf_find_and_replace(wrong, right, x);

}
void choice1() {
	///////////////Initialization/////////////////////
	Dict = new TST();
	DictR = new TST();
	int i = 0;
	string line;
	ifstream myfile("Dictionary1.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			Dict->put(line, line);
			string rl = reverse(line);
			DictR->put(rl, line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	///////////////////////////////////////////

	string y;
	fstream x = open_file(y);
	if (!x.is_open()) {
		cout << "failed" << endl;
		return;
	}
	vector<string> wordsLC = text2words(x);
	vector<string> init_wrong;
	for (string xx : wordsLC) {
		if ((xx.find_first_not_of(' ') != std::string::npos) && (xx.size() != 1)) {
			if (!SpellCheck(xx)) {
				init_wrong.push_back(xx);
			}
		}
	}
	for (string xx : init_wrong) {
		cout << xx << "  ====>  " << WordSuggetion(xx)->toString() << endl;
	}
	x.close();
	/////////////////////////////////////////////////////////////////
	////     till here i only presented wrong words
	/////////////////////////////////////////////////////////////////
	x = open_file_again(y);
	if (!x.is_open()) {
		cout << "failed" << endl;
		return;
	}
	choice1_handle(x);

	x.close();


}
// choice2 is for find and replace functionality
void choice2() {
	waleed_function();
}


//////////////////////joe
class node1
{
private:
	string data;
	node1 *next;
public:
	node1()
	{
		data = "";
		next = nullptr;
	}
	node1(string d)
	{
		data = d;
		next = nullptr;
	}
	string getData() { return data; }
	void setData(string d) { data = d; }
	node1 * getNext() { return next; }
	void setNext(node1 * n) { next = n; }
	friend class linkedlist;
};
class linkedlist
{
private:
	node1 * head;
public:
	linkedlist()
	{
		head = nullptr;
	}
	linkedlist(string d)
	{
		head = new node1(d);
	}
	void printall();
	void addfront(string item);
	void addend(string item);
	void add(string item, int pos);
	void addsort(string item);

	int count();
	bool isempty();
	node1 * gethead() { return head; }

};
void linkedlist::printall()
{
	node1 *p = head;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}
void linkedlist::addfront(string item)
{
	node1 *temp = new node1(item);

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}
int linkedlist::count()
{
	int count = 0;
	node1 *p = head;
	if (p == nullptr)
		return 0;
	while (p->next != nullptr)
	{
		p = p->next;
		count++;
	}
	return count + 1;

}
bool linkedlist::isempty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}
void linkedlist::addend(string item)
{
	if (head == nullptr)
	{
		addfront(item);
	}
	else
	{
		node1 *p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		node1 *n = new node1(item);
		p->next = n;

	}
}
void linkedlist::add(string item, int pos)
{
	if (pos == 1)
		addfront(item);
	else{
		node1 *temp1 = new node1(item);
		node1 *temp = head;
		if (head == nullptr)
		{
			addfront(item);
		}
		else
		{
			for (int i = 0; i < pos - 2; i++)
			{
				temp = temp->next;
				if (temp == nullptr)
				{
					addend(item);
					return;
				}

			}
			temp1->next = temp->next;
			temp->next = temp1;
		}

	}
}
void linkedlist::addsort(string item)
{
	int pos = 1; string s; int flag = 0;
	if (item[1] == 0)
	{
	}
	else
	{

		if (head == nullptr)
		{
			addfront(item);
		}
		else
		{
			node1 *p = head;
			if (item[1] > 96 && item[1] < 123)
			{

				while (p->next != nullptr)
				{

					s = p->data;

					if (item[1] < s[1])
					{
						add(item, pos); flag = 1;
						break;
					}
					p = p->next;
					pos++;
				}
				if (flag == 0)
				{
					addend(item);
				}
			}
			else
			{
				addfront(item);
			}

		}
	}
}
vector<linkedlist>pushalpha(vector<string>words)
{
	vector<linkedlist>alpha(26);
	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];
		if (s[0] >96 && s[0] < 123)
		{
			alpha[s[0] - 97].addsort(s);
		}
	}
	return alpha;
}
char mostused(vector<linkedlist> alpha)
{
	int maxcount = 0; int maxchar = 0;
	for (int i = 0; i < 26; i++)
	{
		int count = alpha[i].count();
		if (count>maxcount)
		{
			maxchar = i;
			maxcount = count;
		}
	}
	return maxchar + 97;
}
vector<string> output(vector<linkedlist> alpha)
{
	vector<string> lines(28);
	for (int i = 0; i < 26; i++)
	{

		node1 * p2;
		p2 = alpha[i].gethead();
		while (p2 != nullptr)
		{

			lines[i] = lines[i] + p2->getData() + "; ";
			p2 = p2->getNext();
		}
		char x = (alpha[i].count() / 10) + 48;
		char y = (alpha[i].count() % 10) + 48;
		lines[i] = lines[i] + "    count is : " + x + y;

	}
	lines[26] = mostused(alpha);
	int counter = 0;
	for (int i = 0; i < 26; i++)
	{
		counter = counter + alpha[i].count();
	}
	string h = "000";
	h[0] = (counter / 100) + 48;
	h[1] = ((counter % 100) / 10) + 48;
	h[2] = (counter % 10) + 48;
	lines[27] = h;
	return lines;
}

void choice3()
{
	fstream x = open_file();
	vector<string> lines = text2words(x);
	vector<linkedlist> alpha = pushalpha(lines);
	vector<string> y = output(alpha);
	output_in_txtfile(y);


}
void choice4()
{
	fstream x = open_file();
	vector<string> lines = file2lines(x);
	vector<linkedlist> alpha = pushalpha(lines);
	vector<string> y = output(alpha);
	output_in_txtfile(y);



}
///////////////////// joe
int main() {

	// we faced an error to get number or character to your choice of functionality you want ...
	//so please just write in main choice1() or choice2() or choice3() or choice4() 


	/*	char in;
	cout << "for find and replace press1" << endl << "for spell checking press2" << endl << "for output statstics for words press3" << endl << "for output statstics for lines press4" << endl;
	cin >> in;

	if (in == 'a')
	{
	choice1();
	}
	else if (in == 'b')
	{
	choice2();
	}
	else if (in == 'c')
	{
	choice3();
	}
	else if (in == 'd')
	{
	choice4();
	}
	else*/
	choice1();
	//choice2();
	//choice3();
	//choice4();
	return 0;
}
//walid.txt 
//C:\Users\walid osama\Desktop\walid.txt
//C:\Users\walid osama\Desktop\coldplay.txt
//C:\Users\walid osama\Desktop\texts\believer.txt
//C:\Users\walid osama\Desktop\texts\walid.txt

void output_file_contents(fstream& x) {
	while (!x.fail()) {
		string s;
		getline(x, s);
		cout << s << endl;
	}
}
vector<string> line2words(string line) {
	istringstream instr(line);
	string temp;
	vector<string> final;
	instr >> temp;
	while (!instr.eof()) {
		if (temp == "," || temp == ".");
		else final.push_back(temp);
		instr >> temp;
	}
	final.push_back(temp);
	return final;
}
void stream_of_words(fstream& x) {
	vector<string> temp = file2lines(x);
	for (string x : temp) {
		vector<string> temp2 = line2words(x);
		for (string xx : temp2) {
			// here xx will be every word in the text except dot and comma ;
			cout << xx << endl;
		}
	}
}
void stream_of_words_nospaceUSE(fstream& x, string &y) {
	vector<string> temp = file2lines(x);
	for (string x : temp) {
		vector<string> temp2 = line2words(x);
		for (string xx : temp2) {
			// here xx will be every word in the text except dot and comma ;
			y += xx;
		}
	}
}
string text2oneString(fstream& x) {
	string temp;
	while (!x.fail()) {
		string s;
		getline(x, s);
		temp += (s + " ");
	}
	return temp;
}
string text2oneString_nospace(fstream& x) {
	string temp;
	stream_of_words_nospaceUSE(x, temp);
	return temp;
}
vector<string> text2words(fstream& x) {
	if (!x.is_open()) {
		cout << "failed " << endl;
		vector<string> my_final;
		return my_final;
	}
	vector<string> my_final;
	vector<string> temp = file2lines(x);
	for (string x : temp) {
		vector<string> temp2 = line2words(x);
		for (string xx : temp2) {
			// here xx will be every word in the text except dot and comma ;word_modifier
			my_final.push_back(word_modifier(xx));
		}
	}
	return my_final;
}




fstream open_file() {
	string file;
	cout << "please enter file path : " << endl;
	getline(cin, file);
	fstream input_data;
	input_data.open(file.c_str());
	return input_data;
}
fstream open_file(string& file) {

	cout << "please enter file path : " << endl;
	getline(cin, file);

	fstream input_data;
	input_data.open(file.c_str());
	return input_data;
}
fstream open_file_again(string& file) {

	fstream input_data;
	input_data.open(file.c_str());
	return input_data;
}
void close_file(fstream& x) {
	x.close();
}
vector<string> file2lines(fstream& x) {
	string temp;
	vector<string> final;

	while (!x.fail()) {
		string s;
		getline(x, s);
		final.push_back(s);
	}
	return final;
}


/////////////////////////////////////////////////////////////////////////
////    these function used in find and replace
/////////////////////////////////////////////////////////////////////////
int return_ascii(char& a) { // note this application modifies original !!
	if ((int)a >= 65 && (int)a <= 90) {
		a += 32;
	}

	if ((int)a >= 97 && (int)a <= 122)
		return  (int)a;
	else return -1;
}
void alphabet_fill(int right[], string pat) { // time complexity O(k) , k is length of "pat"

	///////////////////////////////////////////////////////////////
	/////     this is part where i use my loop to fill alphabet array 
	////      with index of each in the word else -1
	//////////////////////////////////////////////////////////////
	/*int x[26] ;
	alphabet_fill(x, "hello");
	for (int i = 0; i < 26; i++) {
	cout << x[i] <<endl;
	}*/
	for (int i = 0; i < 26; i++) {
		right[i] = -1;
	}

	int * pat_num = new int[pat.size()];
	for (int j = 0; j < pat.size(); j++) {
		pat_num[j] = return_ascii(pat[j]);
	}
	char temp;
	int a;
	for (int i = 0; i< 26; i++) {
		temp = 97 + i;
		for (int j = pat.size() - 1; j >= 0; j--) {
			if ((int)temp == pat_num[j]) {
				right[i] = j;
				break;
			}
		}
	}
}
int hit(string &text, string &pat, int& index, int alphabet[]) {
	int begin = -1;
	int back_steps = 0;
	int alt = index;
	int my_i = pat.size() - 1;
	while (back_steps <= pat.size() - 1) {
		return_ascii(text[alt]);
		if (pat[my_i] == text[alt]) {
			alt--;
			my_i--;
			back_steps++;
		}
		else break;
	}

	if (back_steps == pat.size()) {
		alt++;
		begin = alt;
		index = begin;// return if not -1 then it is hit
		index += pat.size(); // if hit i advance index too , in case i will continue searching
	}
	else if (back_steps == 0) {
		//index += pat.size();
		int ask = return_ascii(text[alt]);
		if (ask == -1) index += pat.size(); // here it is not letter 
		else { // here fault char is letter
			ask -= 97;
			if (alphabet[ask] == -1)  index += pat.size(); //here it is not in the word 
			else { // here it is in the word 
				index += pat.size() - back_steps - 1 - alphabet[ask];
			}
		}
	}
	else { // there was partial match 
		int ask = return_ascii(text[alt]);
		if (ask == -1) index += pat.size(); // here it is not letter 
		else { // here fault char is letter
			ask -= 97;
			if (alphabet[ask] == -1)  index += pat.size(); //here it is not in the word 
			else { // here it is in the word 
				int teto = alphabet[ask];
				index += pat.size() - back_steps - 1 - teto;

			}
		}

	}

	return begin; // if hit , it will get index of first letter
}
void find_and_replace(string &text, string &pat, int alphabet[], string &replace) {
	int index = pat.size() - 1;

	while (index < text.size()) {

		int temp = hit(text, pat, index, alphabet);

		if (temp != -1) {
			text.erase(temp, pat.size());
			text.insert(temp, replace);
			//break;
		}
	}
}
void reset_handle(char &condition) {
	cout << "################################################################################################" << endl;
	cout << "################################################################################################" << endl;
	cout << "do you want to find and replace more words ? y/n" << endl;
	cin >> condition;
}
void output_in_txtfile(vector<string> x) {

	string name;
	cout << endl << "please write the output file's name : " << endl;
	cin >> name;
	ofstream temp;
	temp.open(name);
	for (string k : x) {
		temp << k << endl;
	}
	temp.close();
}
void waleed_function() {

	fstream x = open_file();
	vector<string> lines = file2lines(x);

	cout << endl << endl;
	char condition = 'y';

	do {
		string pat;
		cout << "enter the word you want to find  :" << endl;
		cin >> pat;
		int alphabet[26];
		alphabet_fill(alphabet, pat); // letters have 0 based index from pattern word 	
		string replace;
		cout << "enter the replace you want  :" << endl;
		cin >> replace;
		cout << endl << endl;

		for (int i = 0; i < lines.size(); i++) {
			find_and_replace(lines[i], pat, alphabet, replace);
			//	cout << lines[i] <<endl;
		}

		reset_handle(condition);

	} while (condition == 'y' || condition == 'Y');

	close_file(x);
	output_in_txtfile(lines);
}
string word_modifier(string x) {
	int temp;
	string temp2;
	for (int i = 0; i < x.size(); i++) {
		temp = return_ascii(x[i]);
		if (temp >= 97 && temp <= 122) {
			temp2 += temp;
		}
	}
	return temp2;
}
void groupOf_find_and_replace(vector<string> wrong, vector<string > right, fstream& x) {
	// use case :
	// fstream x = open_file();
	/*vector<string> wrong = { "believer" , "pain" , "first" , "second" };
	vector<string> right = { "mo2men" , "waga3" , "FIRST" , "SECOND" };
	groupOf_find_and_replace(wrong, right, x);*/
	///////////////////////////////////////////////////////////////////////////////////
	if (!x.is_open()) {
		cout << "failed" << endl;
		return;
	}
	vector<string> lines = file2lines(x);
	for (int i = 0; i < wrong.size(); i++) {
		int alphabet[26];
		alphabet_fill(alphabet, wrong[i]);
		for (int j = 0; j < lines.size(); j++) {
			find_and_replace(lines[j], wrong[i], alphabet, right[i]);
			//	cout << lines[i] <<endl;
		}
	}
	close_file(x);
	output_in_txtfile(lines);
}
#ifndef STATUS_H
#define STATUS_H
class Status
{
public:
	void set_content(char* input);
	void show_status();

private:
	char* content; //for first module - text only
	char* date_of_status;
};

#endif // !STATUS_H
#ifndef BUTTON_H
#define BUTTON_H

class Button{
	private:
		int m_pin;
		bool m_state;
	public:
    Button();
		Button(int pin);
    Button(Button& other);
		~Button();
		void checkIfPushed();
		bool isPushed();
};

#endif

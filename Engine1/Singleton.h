#pragma once

template<class T>
class Singleton
{
private:

	static T * instance;

public:

	virtual ~Singleton()
	{

	}

	static T * Get()
	{
		if (instance != nullptr)
			return instance;
		instance = new T();
	}
};

template <class T>
T * Singleton<T>::instance = nullptr;
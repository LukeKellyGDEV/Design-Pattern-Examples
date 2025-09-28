#pragma once
class SingletonEx2
{
public:
	SingletonEx2(const SingletonEx2&) = delete;

	static SingletonEx2& Get()
	{
		static SingletonEx2 s_Instance;
		return s_Instance;
	}

	static float GetRandomFloat() { return Get().RandomFloat(); }
private:
	float RandomFloat() { return m_RandomGenerator; }
	
	SingletonEx2() {}

	float m_RandomGenerator = 0.5f;
};


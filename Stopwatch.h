
class Stopwatch
{
public:
	Stopwatch();

	void Start();
	void Stop();
	__int64 ElapsedTicks();
	__int64 ElapsedMilliseconds();

private:

	__int64 Now();

	__int64 m_frequency;
	__int64 m_start;
	__int64 m_stop;

};
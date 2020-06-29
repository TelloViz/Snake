#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "SnakeStates.hpp"
#include "World.hpp" 
#include "Snake.hpp"







enum State			{PENDING, PLAYING, PAUSED, LOSE};

class Game
{
public:
					Game();
					~Game();
	void				Run();


private: // Private Method

	friend			SnakeState::PendingState;
	friend			SnakeState::PlayingState;
	//friend			SnakeState::PauseState;
	//friend			SnakeState::LoseState;



	void				resetGame();
	void				initDefaultState();
	void				transitionToState(IState* state);

	void				Input();
	void				Update();
	void				Render();

	bool				IsHighScore() const;

	sf::RenderWindow&	Window();

	void				SignalClose(); // TODO: Define;

private: // Private Data
	bool				m_isHighScore;
	World			m_world;	

	sf::RenderWindow	m_window;
	
	sf::Clock			m_clock;
	float			m_elapsed;
	float			m_fps;
	float			m_frameTime;

	std::string		m_highScoreFilePath;

	int				m_highScore;

	IState*			m_pCurrentState;
	State			m_state;
	
};


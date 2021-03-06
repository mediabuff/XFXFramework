// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include <Game.h>

namespace XFX
{
	const Type GameComponentTypeInfo("GameComponent", "XFX::GameComponent", TypeCode::Object);

	bool GameComponent::getEnabled() const
	{
		return _enabled;
	}

	void GameComponent::setEnabled(const bool value)
	{
		if(_enabled != value)
		{
			_enabled = value;
			OnEnabledChanged(this, EventArgs::Empty);
		}
	}

	Game* GameComponent::getGame() const
	{
		return _game;
	}

	int GameComponent::getUpdateOrder() const
	{
		return _updateOrder;
	}

	void GameComponent::setUpdateOrder(const int value)
	{
		if(_updateOrder != value)
		{
			_updateOrder = value;
			OnUpdateOrderChanged(this, EventArgs::Empty);
		}
	}

	void GameComponent::Dispose()
	{
		Dispose(true);
	}

	void GameComponent::Dispose(bool disposing)
	{
		if (!_disposed)
		{
			_disposed = true;
			Disposed(this, EventArgs::Empty);
		}
	}

	GameComponent::GameComponent(Game * const game)
	{
		_game = game;
		_enabled = true;
	}

	GameComponent::~GameComponent()
	{
		Dispose(false);
	}

	const Type& GameComponent::GetType()
	{
		return GameComponentTypeInfo;
	}
	
	void GameComponent::Initialize()
	{
	}

	void GameComponent::OnEnabledChanged(Object * const sender, EventArgs * const args)
	{
		EnabledChanged(sender, args);
	}

	void GameComponent::OnUpdateOrderChanged(Object * const sender, EventArgs * const args)
	{
		UpdateOrderChanged(sender, args);
	}

	void GameComponent::Update(GameTime gameTime)
	{
	}
}

/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the TV class that inherits from the SmartAppliance class.
 * Dependencies: "ha_pch.h", "TV.h"
 * 
 * Last modified: 4/26/2024
 * Added exception handling
 * Added parametrized constructor for the TV class.
 * Added GetState method.
 */

#include "ha_pch.h"
#include "TV.h"

namespace HomeAutomation {

	TV::TV(const std::string& name, const std::string& brand, const std::string& model, const std::string& netAddr)
	{
		SetName(name);
		SetBrand(brand);
		SetModel(model);
		SetNetAddr(netAddr);
		m_isOn = false;
		m_CurrentChannel = 0;
		m_Volume = 50;
	}

	void TV::ToggleOnOff()
	{
		m_isOn = !m_isOn;
	}

	bool TV::IsOn() const
	{
		return m_isOn;
	}

	void TV::SetChannel(int currentChannel)
	{
		// Handle exceptions for invalid currentChannel values
		if (currentChannel < 0 || currentChannel > 999)
		{
			throw std::invalid_argument("Invalid channel value. Channel must be between 0 and 999.");
		}
		m_CurrentChannel = currentChannel;
	}

	int TV::GetChannel() const
	{
		return m_CurrentChannel;
	}

	int TV::GetVolume() const
	{
		return m_Volume;
	}

	void TV::ChangeChannelUp()
	{
		// Handle exceptions for channel out of range
		if (m_CurrentChannel == 999)
		{
			m_CurrentChannel = 0;
		}
		m_CurrentChannel++;
	}

	void TV::ChangeChannelDown()
	{
		// Handle exceptions for channel out of range
		if (m_CurrentChannel == 0)
		{
			m_CurrentChannel = 999;
		}
		m_CurrentChannel--;
	}

	void TV::IncreaseVolume()
	{
		// Handle exceptions for volume out of range
		if (m_Volume == 100)
		{
			// do nothing
		}
		else {
			m_Volume++;
		}
	}

	void TV::DecreaseVolume()
	{
		// Handle exceptions for volume out of range
		if (m_Volume == 0)
		{
			// do nothing
		}
		else {
			m_Volume--;
		}
	}

	void TV::PrintStatus()
	{
		std::cout << "TV Status: " << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Brand: " << GetBrand() << std::endl;
		std::cout << "Model: " << GetModel() << std::endl;
		std::cout << "Network Address: " << GetNetAddr() << std::endl;
		std::cout << "Current Channel: " << GetChannel() << std::endl;
		std::cout << "Volume: " << GetVolume() << std::endl;
		std::cout << "Is On: " << IsOn() << std::endl;
	}

	std::string TV::GetState()
	{
		std::string state = "TV State: ";
		state += "Name: " + GetName() + ", ";
		state += "Brand: " + GetBrand() + ", ";
		state += "Model: " + GetModel() + ", ";
		state += "Network Address: " + GetNetAddr() + ", ";
		state += "Current Channel: " + std::to_string(GetChannel()) + ", ";
		state += "Volume: " + std::to_string(GetVolume()) + ", ";
		state += "Is On: " + std::to_string(IsOn());

		return state;
	}

} // namespace HomeAutomation

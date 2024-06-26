/**
 * Student Name: Krystian Spiewak
 * File description: This file contains the implementation of the SmartAppliance abstract class that individual smart appliances will inherit from.
 * Dependencies: "ha_pch.h", "SmartAppliance.h"
 * 
 * Last modified: 04/26/2024
 * Added default constructor and constructor with parameters.
 */

#include "ha_pch.h"
#include "SmartAppliance.h"

namespace HomeAutomation {

	SmartAppliance::SmartAppliance(const std::string& m_Name, const std::string& m_Brand, const std::string& m_Model, const std::string& m_NetAddr)
		: m_Name(m_Name), m_Brand(m_Brand), m_Model(m_Model), m_NetAddr(m_NetAddr)
	{
	}

	void SmartAppliance::SetName(std::string name)
	{
		m_Name = name;
	}

	void SmartAppliance::SetBrand(std::string brand)
	{
		m_Brand = brand;
	}

	void SmartAppliance::SetModel(std::string model)
	{
		m_Model = model;
	}

	void SmartAppliance::SetNetAddr(std::string netAddr)
	{
		if (IsValidIPAddress(netAddr)) {
			m_NetAddr = netAddr;
		}
		else { // Throw an exception if the IP address is invalid
			throw std::invalid_argument("Invalid IP address format.");
		}
	}

	std::string SmartAppliance::GetName()
	{
		return m_Name;
	}

	std::string SmartAppliance::GetBrand()
	{
		return m_Brand;
	}

	std::string SmartAppliance::GetModel()
	{
		return m_Model;
	}

	std::string SmartAppliance::GetNetAddr()
	{
		return m_NetAddr;
	}

} // namespace HomeAutomation

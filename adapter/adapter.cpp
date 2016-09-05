/*
 * Example of `adapter' design pattern
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

typedef int Cable; // wire with electrons :-)

/* Adaptee (source) interface */
class EuropeanSocketInterface
{
    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0; 
        virtual Cable earth() = 0;
};

/* Adaptee */
class Socket : public EuropeanSocketInterface
{
    public:
        int voltage() { return 230; }

        Cable live() { return 1; }
        Cable neutral() { return -1; }
        Cable earth() { return 0; }
};

/* Target interface */
class USASocketInterface
{
    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0;
};

/* The Adapter */
class Adapter : public USASocketInterface
{
    EuropeanSocketInterface* socket;

    public:
        void plugIn(EuropeanSocketInterface* outlet)
        {
           
            socket = outlet;
        }

        //int voltage() { return socket->voltage(); } // return the voltage directly
        int voltage() { return 110; } // convert of 230 to 110
        Cable live() { return socket->live(); } // return the socket live
        Cable neutral() { return socket->neutral(); } // return the socket neutral
};

/* Client */
class ElectricKettle
{
    USASocketInterface* power;

    public:
        void plugIn(USASocketInterface* supply)
        {
            power = supply;
        }

        void boil()
        {
            if (power->voltage() > 110) //adapter  voltage 
            {
                std::cout << "Kettle is on fire!" << std::endl;
                return;
            }

            if (power->live() == 1 && power->neutral() == -1) // adapter live and neutral
            {
                std::cout << "Coffee time!" << std::endl;
            }
        }
};


int main()
{
    Socket* socket = new Socket;
    Adapter* adapter = new Adapter;
    ElectricKettle* kettle = new ElectricKettle;

    /* Pluging in. */
    adapter->plugIn(socket);
    kettle->plugIn(adapter);

    /* Having coffee */
    kettle->boil();

    return 0;
}
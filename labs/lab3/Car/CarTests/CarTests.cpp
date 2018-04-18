// CarTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Car/Car.h"
#include "../Car/CarControl.h"

CCar car;

stringstream input;
stringstream output;

void VerifyTurnOnGear(Gear currentGear, Gear expectedGear, bool successOperation)
{
	CHECK(car.GetGear() == currentGear);
	CHECK(car.SetGear(expectedGear) == successOperation);
}

void VerifySetSpeed(Gear currentGear, int speed, bool successOperation)
{
	CHECK(car.GetGear() == currentGear);
	CHECK(car.SetSpeed(speed) == successOperation);
}

CCarControl carControl(car, input, output);

void VerifyCommandHandling(const string& command, const string& expectedOutput)
{
	input = stringstream();
	output = stringstream();
	CHECK(input << command);
	CHECK(carControl.HandleCommand());
	CHECK(input.eof());
	CHECK(output.str() == expectedOutput);
}

TEST_CASE("Car Tests")
{
	SECTION("engine_is_turn_off_by_default")
	{
		CHECK(!car.IsEngineTurnOn());
	}
	SECTION("speed_is_zero_by_default")
	{
		CHECK(car.GetSpeed() == 0);
	}
	SECTION("gear_is_neutral_by_default")
	{
		CHECK(car.GetGear() == Gear::Neutral);
	}
	SECTION("direction_is_none_by_default")
	{
		CHECK(car.GetDirection() == Direction::None);
	}
	SECTION("when_enigne_is_turn_off")
	{
		SECTION("cannot_turn_off_engine_twice")
		{
			CHECK(!car.TurnOffEngine());
		}
		SECTION("cannot_change_gear")
		{
			VerifyTurnOnGear(Gear::Neutral, Gear::Reverse, false);
			VerifyTurnOnGear(Gear::Neutral, Gear::First, false);
		}
		SECTION("cannot_change_speed")
		{
			VerifySetSpeed(Gear::Neutral, 10, false);
		}
		SECTION("can_turn_on_engine")
		{
			CHECK(car.TurnOnEngine());
			CHECK(car.IsEngineTurnOn());
		}
	}
	SECTION("when_engine_is_turn_on")
	{
		SECTION("cannot_turn_on_engine_twice")
		{
			car.TurnOnEngine();
			CHECK(!car.TurnOnEngine());
		}
		SECTION("can_change_gear_from_neutral_to_first")
		{
			car.TurnOnEngine();
			VerifyTurnOnGear(Gear::Neutral, Gear::First, true);
		}
		SECTION("can_turn_off_engine_when_car_is_standing_still")
		{
			car.TurnOnEngine();
			CHECK(!car.TurnOffEngine());
		}
	}
}

TEST_CASE("CarControl Tests")
{
	SECTION("can_give_information_about_car_which_is_set_by_default")
	{
		VerifyCommandHandling("Info", "Engine is turned on\nGear is 1\nDirection is 0\nSpeed is 0\n");
	}
	SECTION("can_turn_on_engine")
	{
		VerifyCommandHandling("EngineOn", "Engine is already turned on\n");
	}
	SECTION("when_enigne_is_turn_off")
	{
		SECTION("cannot_turn_off_engine_twice")
		{
			VerifyCommandHandling("EngineOff", "Engine was not turned off\n");
		}
		SECTION("cannot_change_gear")
		{
			VerifyCommandHandling("SetGear 1", "Gear was change\n");
		}
		SECTION("cannot_change_speed")
		{
			VerifyCommandHandling("SetSpeed 10", "Speed was change\n");
		}
		SECTION("can_turn_on_engine")
		{
			VerifyCommandHandling("EngineOn", "Engine is already turned on\n");
		}
	}
	SECTION("when_enigne_is_turn_on")
	{
		SECTION("cannot_turn_on_engine_twice")
		{
			car.TurnOnEngine();
			VerifyCommandHandling("EngineOn", "Engine is already turned on\n");
		}
		SECTION("can_change_gear_from_neutral_to_first")
		{
			car.TurnOnEngine();
			VerifyCommandHandling("SetGear 1", "Gear was change\n");
		}
		SECTION("can_change_gear_from_reverse_to_first_at_zero_speed")
		{
			car.TurnOnEngine();
			VerifyCommandHandling("SetGear -1", "Gear wasn't change\n");
			VerifyCommandHandling("SetGear 1", "Gear was change\n");
		}
		SECTION("can_change_gear_from_first_to_reverse_at_zero_speed")
		{
			car.TurnOnEngine();
			VerifyCommandHandling("SetGear 1", "Gear was change\n");
			VerifyCommandHandling("SetGear -1", "Gear wasn't change\n");
		}
	}
}
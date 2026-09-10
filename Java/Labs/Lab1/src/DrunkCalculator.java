/**********************************************************************
* This program will do some calculations on if you will make the dunk *
* for CIS-132														  *
* By Harris Domangue 												  *
***********************************************************************/

//imports
import static java.lang.System.out;   // import system.out

// This class will do some calculations for a dunk
public class DrunkCalculator {

	public static void main(String[] args) {
		// declare variables
		int bodyMass = 95, height = 5; // declaration of body mass and height variables
		final double gravity = 32.174; // this contains the consistent gravitational force
		double mLeapHeight = 10-height*1.3; // this stores the minimum leap height
		double jumpEnergy = bodyMass * gravity * mLeapHeight; // this stores the jump energy
		double iJumpSpeed = Math.sqrt(2 * gravity * mLeapHeight); // this store the initial jumping speed 
		double hangTime = Math.sqrt(8 * mLeapHeight/gravity); // this stores the hang time
		
		// display variables to user
		out.println("The minimum leap height required is: " + mLeapHeight + " ft.");
		out.println("The jump energy required is: " + jumpEnergy + " ft-lbs.");
		out.println("The initial jumping speed required is: " + iJumpSpeed + " ft/sec.");
		out.println("The hang time required is: " + hangTime + " secs.");
	}

}

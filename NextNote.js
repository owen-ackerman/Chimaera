inlets = 1;
outlets = 1;

var CurrentNote = 0;
var Interval = 0;
var Scale;
	
	
function list() {
	
	if (arguments.length > 1) {
	Scale = arrayfromargs(messagename, arguments);
	//post("received Scale: " + Scale + "\n");
	}
	}
	
function interval(v) {

	Interval = v;
	post("received Interval: " + Interval + "\n");
	NextNote();

	}
	
function currentNote(v) {
	
	CurrentNote = v;
	post("received CurrentNote: " + CurrentNote + "\n");
	}
	

function NextNote() {
	var Note = CurrentNote % 12;
	var Octave = Math.floor(CurrentNote / 12);
	post("CurrentNote: " + CurrentNote + "\n");
	//post("Octave: " + Octave + "\n");
	//post("Note: " + Note + "\n");
	post("received Scale: " + Scale + "\n");
	
	var SearchIndex = Math.abs(Interval);
	var index = 1; // just to avoid the impossible case of an infinite loop
	//Set the indexing to look up or down the scale
	if (Interval > 0) { 
		index = 1;
	} else if (Interval < 0) { 
		index = -1; }
	else if (Interval === 0) {
		SearchIndex = 0; // if our interval is zero we don't search for next note
	}
	post("Search Index Pre loop: " + SearchIndex + "  Pre Loop Index: " + index + "\n");
	
	var NextNote = Note;
	var i = 0;
	while (SearchIndex !== 0) {
		NextNote = NextNote + index;
		Octave = Octave + Math.floor(NextNote/12);
		NextNote = (NextNote + 12)  % 12;
	//	if (NextNote < 0) {
	//		if (Scale[((NextNote + 12)  % 12)] === 1) { SearchIndex = SearchIndex - 1 } ;
	//	}
		//else {
			if (Scale[NextNote] === 1) { SearchIndex = SearchIndex - 1 } ;
		//}
		//i = i + 1;
		//post("i : " + i + "\n");
		//post("Search Index : " + SearchIndex + "\n");
		//if (i > 100) { break; }
		}
	//CurrentNote = ((((NextNote + 12) % 12) + 12*(Math.floor(NextNote / 12) + Octave)) % 127);
	CurrentNote = ((NextNote + 12*Octave) % 127);
	if (CurrentNote < 0) { CurrentNote = CurrentNote + 127 };
	outlet(0, CurrentNote);
	}
	

//arrayfromargs(
	
//	outlet(0, thingToOutlet);
	
//	if ( i === 3) {
		
//	else if (i !== 4) {
//		}
	
	
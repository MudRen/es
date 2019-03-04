//#pragma save_binary

// doors.c
// The standard door object. Any room (or other object if you like) that
// contains a door needs to inherit this file.
// Originally written by Rusty@TMI-2, 11-92.
// He lost his access in January 1993. Mobydick@TMI-2 went back and whipped
// the code into shape for the release.
// Originally part of room.c. Mobydick seperated in into two files, rooms
// and doors, on 2-17-93. This was done to save memory since most rooms do
// not contain doors and do not need this code.

// Prototypes for functions defined in room.c.

varargs void set (string foo, mixed data, string perms) ;
mixed query (string foo) ;
void add (string foo, mixed data) ;


// Homegrown prototypes.

void set_desc (string dir) ;
void initialize_link (string dir) ;

// This function creates a door for a previously existing exit.
// If all you want is a door that opens and closes, this is enough.
// Ex. create_door("east", "west", "A simple wooden door");
//

varargs void create_door( string dir, string linked_exit, mapping door_info )
{
	if( !mapp(door_info) || undefinedp(door_info["name"]) )
		return;

	door_info["linked"] = linked_exit;

	if( undefinedp(door_info["c_name"]) )
		door_info["c_name"] = door_info["name"];

	if( undefinedp(door_info["status"]) )
		door_info["status"] = "open";
/*
	if( undefinedp(door_info["desc"]) )
		door_info["desc"] = "You see "+article(door_info["name"])+door_info["name"]+".\n";

	if( undefinedp(door_info["c_desc"]) )
		door_info["c_desc"] = door_info["desc"];
*/
	set( "doors/"+dir, door_info );
	set_desc(dir) ;
	initialize_link(dir) ;
	return;
}

// This function returns direction of the door specified
// by keyword or 0 for none.

mixed query_door(string keyword)
{
	mapping doors;
	string *dirs;
	int i;

	doors = query("doors");
	if( !doors || !mapp(doors) || sizeof(doors)<1 ) return 0;
	dirs = keys(doors);
	for( i=0; i<sizeof(dirs); i++ )
	{
		if( !undefinedp(doors[dirs[i]]["keyword"]) 
			&& member_array(keyword, doors[dirs[i]]["keyword"])!=-1 )
			return dirs[i];
	}
	return 0;
}

// A function to set various door attributes.
// For value use "open" or "closed" or "locked"..

void set_status(string dir, string value)
{
   set("doors/"+dir+"/status", value);
   set_desc(dir);
}

void set_desc( string dir )
{
/*
	set( "item_desc/" + dir + " door",
		query("doors/"+dir+"/desc") + ". It is "+ 
		query("doors/"+dir+"/status") +".\n" );
*/
	set( "item_desc/" + dir + " door",
		query("doors/"+dir+"/c_desc") + "����������"+ 
		to_chinese(query("doors/"+dir+"/status")) +"�ġ�\n" );
	return;
}

// This function initializes a doorway linkage. When you create a new
// door with a link, this function queries the linked door and sets the
// status of this door to match the status of that door.

void initialize_link (string dir)
{
	int i;
	string ob_dir, ob_status, link ;
	object ob;
	mapping doors;

	link = this_object()->query("doors/"+dir+"/linked") ;
	if (link && link!="none") {
		if (ob = find_object((string)query("exits/"+dir))) {
			ob_dir = (string)query("doors/"+dir+"/linked");
			ob_status = (string)ob->query("doors/"+ob_dir+"/status") ;
			set_status(dir, ob_status);
		}
	}
	return;
}

// This function updates a doorway link. When called, it finds the door
// linked to this door and sets that door's status to match this door.
// The difference between initialize_link and update_link is that initialize
// causes this room's door to match the remote door, but update causes the
// remote door to match this room's door.

void update_link (string dir)
{
   int i;
   string link ;
   string ob_dir;
   string door_stat ;
   string old_stat ;
   object ob;

	link = query("doors/"+dir+"/linked") ;
	if (link && link != "none") {
		if (ob = find_object((string)query("exits/"+dir))) {
			door_stat = (string)query("doors/"+dir+"/status") ;
			ob_dir = (string)query("doors/"+dir+"/linked");
			old_stat = (string)ob->query("doors/"+ob_dir+"/status") ;
			ob->set_status(ob_dir, door_stat) ;
			switch (door_stat) {
				case "open" : {
					tell_room (ob, to_chinese(ob_dir)+"�ߵ���ͻȻ��ˢ����һ���ƿ������ײ����ı���.\n") ;
					break ;
				}
				case "locked" : {
					tell_room(ob,to_chinese(ob_dir)+"�ߵ��š���������һ��������������.\n") ;
					break ;
				}
				case "closed" : {
					if (old_stat=="locked") {
						tell_room (ob, to_chinese(ob_dir)+"�ߵ��ŷ�������߿����һ����������������.\n") ;
					} else
						tell_room (ob, to_chinese(ob_dir)+"�ߵ���ͻȻ��������һ�����ϣ���������һ���� .\n") ;
					break ;
				}
			}
		}
	}
	return;
}
/* EOF */

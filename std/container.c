////#pragma save_binary

// container.c
// Hacked together by Mobydick@TMI-2 on 9-29-92 from two pre-existing files.
// The first, bag_logic.c, was mostly written by Brian@TMI. The second,
// container.c, was written by Sulam@TMI. Original documentation follows:
/*
 * bag_logic.c
 * Written by Brian Nov 1991
 * Added get all from container Feb 6 1992
 *
 * This works in conjunction with my move and container to make it very easy
 * to make containers.
 *
 * set possible_to_close = 1; if you want the container to be closable.
 *
 * somewhat modifed by Truilkan@TMI - 92/04/21
 *
 * this has a query_long() that will be checked for when you call 
 * query("long").  any object inheriting std/bag_logic should not directly
 * inherit std/Object or /std/container.
 */
// Mobydick made some major changes while getting mass and bulk to work properly
// Mobydick added money functions, 10-12-92
// Mobydick cleaned out some unused variables and functions, 10-14-92.
// Watcher added prevent_get and prevent_drop aspect checks, 3-5-93.
// Watcher added vision checks and made a few bug fixes, 4-13-93.
// Annihilator made lots of changes here. 

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit CONTAINER_OBJECT;

string c_open_long_desc, c_closed_long_desc;
 static int possible_to_close;
 static int is_closed;

int receive_objects();

void create()
{
	seteuid(getuid()) ;
	set("long","@@query_c_long");
}

void init()
{
   add_action("get_from","get");
   add_action("put_into","put");
   add_action("open_container","open");
   add_action("close_container","close");
}

int put_into(string str)
{
	int res, num, has, weight, rate;
	object ths,tht,ob ;
	string athis,that, word ;

	if (!str)
		return notify_fail( "ָ���ʽ: put <��Ʒ> in <����>\n") ;
 
	//  Check to make sure the person can see what they are doing.
	if( !this_player()->query("vision") ) {
		write( "��ʲ��Ҳ������....��\n" );
		return 1;
	}
 
	//  Check for the form "put 10 gold in bag".
	if(sscanf(str,"%d %s into %s",num, athis, that)==3) {
                if( query("prevent_put_money") ) {
			write( "�Բ���, �Ҳ����˱���Ǯ��\n");
			return 1;
		}
		if(num < 1) { 
			write( "Ǯ�ҵĸ������ٱ�����һö��\n");
			return 1;
		}
		tht = present(that, this_player()) ;
		if( !tht ) tht = present(that,environment(this_player())) ;
		if( !tht ) {
			write( "Ҫ��Ǯ�ҷŽ����\n");
			return 1;
		}
		// Is the container open?
		if( !receive_objects() ) {
			write( "������ȴ�����\n") ;
			return 1;
		}
		if( tht!=this_object() ) return 0;

		if( !this_player()->debit(athis, num) ) {
			write( "��û�������" + to_chinese(athis+" coin") + "��\n") ;
			return 1;
		}
		ob = clone_object(COINS);
		ob->set_type(athis);
		ob->set_number(num);
		res = ob->move(tht);
		
		if(res!=MOVE_OK) {
			ob->remove() ;
			write( "���Ѿ����ˣ��Ų���ȥ��\n");
			return 1;
		}

		if (num==1) word= "coin" ; else word="coins" ;
		write( sprintf( "��� %d ö%s�Ž�%s��\n", num, to_chinese(athis+" coin"), query("c_name")) );
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+"�� "+num+" ö"+to_chinese(athis+" coin")+"�Ž�"
				+ tht->query("cap_name")+"��\n",
			this_player());
		return 1 ;
	}
 
	//  Check for the stand "put thingy in bag" format.
	if(!stringp(str) || (sscanf(str, "%s in %s", athis, that) != 2 &&
		sscanf(str, "%s into %s", athis, that) != 2))  return 0;
 
	ths = present(athis, this_player());
 
	if(!ths) {
		write( "��û������������\n");
		return 1;
	}
 
	tht = present(that, this_player());
	if(!tht) tht = present(that, environment(this_player()));
 
	if(!tht) {
		write( "����û������������\n");
		return 1;
	}
 
	if(tht != this_object())  return 0;	// Keep on looking ...

	if((int)ths->query("prevent_drop")) {
		write( "��û�а취����������Ž�ȥ��\n");
		return 1;
	}
 
	if((int)ths->query("prevent_insert")) {
		write( "�㲻�ܰ����ֶ����Ž�ȥ��\n");
		return 1;
	}

	if(!tht->receive_objects()) {
		write( "������Ȱ����򿪡�\n");
		return 1;
	}

	weight = ths->query("weight");

	// This is weight modification stuff.
	rate = (int)query("weight_apply");
	if( rate > 0 && rate < 200 ) weight = weight * rate / 100;
	if( weight < 1 ) weight = 1;

	res = (int)ths->move(tht);

	if(res == MOVE_OK) {
// When we put the object into the container, the mass of the container has
// to go up.
		add("weight", weight);

// If the player is carrying the container, his capacity has to go down.
 
		if(environment(this_object())==this_player())
			this_player()->add("load", weight);
		write( "���" + ths->query("short") + "�Ž�" +tht->query("short")+ "�\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "��" + ths->query("short") + "�Ž�" + tht->query("short") + "��\n",
			this_player());
		return 1;
	}
 
	if(res == MOVE_NO_ROOM) 
		write( "����ռ䲻����\n");
 
	else if(res == MOVE_TOO_HEAVY) 
		write( "��������̫���ˡ�\n");
 
	else if(res == MOVE_NOT_ALLOWED) 
		write( "�㲻��������Ŷ�����\n");
 
	return 1;
}
 

int get_from(string str)
{
	int res, i, num, has, weight, rate;
	object ths, tht, *contents;
	object ob2 ;
	string this1, that, word, c_word;

	if (!str) return notify_fail( "ָ���ʽ: get <����> from <����>\n");
 
	//  Check to see if the user can see what they are doing.
	if(!this_player()->query("vision")) {
// if this container hold any light source, then we can look into it
// add by Ruby@ES at 95/11/24
		contents = all_inventory(this_object());
		for ( i = sizeof(contents)-1 ; i >=0 ; i-- )
			if ( contents[i]->query("light") ) break ;
		if ( i < 0 ) {
			write( "��ʲ��Ҳ��������\n");
			return 1;
		}
	}
 
	// Check for the form "get 20 gold from sack".
	if ( sscanf(str, "%d %s from %s", num, this1, that )==3 ) {
		tht = present( that, this_player());
		if(!tht) tht = present(that, environment(this_player()));
		if(!tht) return notify_fail( "����û���κν��� " + that + " �Ķ�����\n");
		if( tht!=this_object() ) return 0;
 
		// Is it closed?
		if( !tht->receive_objects() ) return notify_fail( "������Ƚ����򿪡�\n");

		if( tht->query("prevent_get") ) return notify_fail( "�㲻�ܴ������������κζ�����\n");
 
		ths = present(this1, tht);
		if (!ths) return notify_fail( "������û������������\n");

		if (ths->query_number()<num )
			return notify_fail( "������û�������"+to_chinese(this1, " coin") +"��\n");

		this_player()->credit( ths->query_type(), num );
		ths->set_number( (int)ths->query_number()-num );

		if (num==1) word="coin"; else word = "coins";
		write( "���"+tht->query("c_name")+"���ó� "+num+" ö"+to_chinese(this1+" coin")+"��\n" ) ;
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+"��"+tht->query("c_name")+"���ó� "+num+" ö"+to_chinese(this1+" coin")+"��\n",
			this_player() );
		return 1;
	}

// Check for the form "get thingy from sack".
// This may or may not be choking on money. I hope not...
	if (stringp(str) && sscanf(str,"%s from %s", this1, that) == 2) {
		if( tht= present(that, this_player()) ||
				(tht= present(that, environment(this_player()))) ) {
			if (tht!=this_object()) return 0;
			if (tht->receive_objects()) {
				if (this1 != "all") {
					ths = present(this1, tht);
					if(!ths) return notify_fail( "������û������������\n") ;

					if((int)ths->query("prevent_get"))
						return notify_fail( "�㲻�ܴ������������κζ�����\n");
 
					weight = ths->query("weight");
					rate = (int)query( "weight_apply" );
					if( rate > 0 && rate < 200 ) weight = weight * rate / 100;
					if( weight < 1 ) weight = 1;

					word = ths->query("short");
					c_word = ths->query("short");
					res = (int)ths->move(this_player());
					if( res == MOVE_OK ) {
// When we get an object out of a container, the mass of the container goes
// down, but the bulk does not go down.
						add ("weight", -weight);
						if( environment(this_object()) ) 
							environment(this_object())->add( "load", -weight );
						write ( "���"+tht->query("short")+"���ó�"+c_word+"��\n");
						tell_room( environment(this_player()), 
							this_player()->query("c_name")+"��"+
							tht->query("short") + "���ó�"+c_word+"��\n",
							this_player() );
						return 1;
					}
					if( res == MOVE_NOT_ALLOWED ) 
						notify_fail( "��û�а취��������������\n");
					if( res == MOVE_NO_ROOM )
						notify_fail( "������û�ж��ŵĿ�λ��\n");
					// This should never happen.
					if( res == MOVE_TOO_HEAVY )
						notify_fail("It is too heavy.\n");
					//if (environment(this_object())==this_player())
					//	this_player()->add("load",weight);
					return 0;
				}
// If we got here, it means we're doing a "get all from container".
				contents = all_inventory(tht);
				rate = (int)query("weight_apply");
				if( rate < 1 || rate > 200 ) rate = 100;
				if (sizeof(contents) > 0 ) {
					for (i=0;i<sizeof(contents);i++) {
						ths = contents[i];
 
						if((int)ths->query("prevent_get")) {
							write( "�㲻������" + ths->query("short") + "��\n");
							continue;
						}
 
						weight = (int)ths->query("weight") * rate / 100;
						if( weight < 1 ) weight = 1;
						word = ths->query("short") ;
						c_word = ths->query("short");
// When the object is removed from the container, if the player is holding
// the container then his capacity goes up.
						res = (int)ths->move(this_player());
						if (res == MOVE_OK) {
// Change the mass of the container.
							add ("weight", -weight);
							if( environment(this_object()) ) 
								environment(this_object())->add( "load", -weight );
							write( "���"+tht->query("short")+"���ó�"+c_word+"��\n") ;
							tell_room( environment(this_player()), 
								this_player()->query("c_name")+"��"+
								tht->query("short")+"���ó�"+c_word+"��\n",
								this_player() );
						}
					}
					return 1;
				}
				write( "������ʲ��Ҳû�С�\n");
			    return 1;
			}
			return notify_fail( "����û������������\n");
		}
		return notify_fail( "���ǹ����ġ�\n");
	}
	return 0;
}

void set_c_closed_long(string str)
{
	c_closed_long_desc = str;
}

void set_c_open_long(string str)
{
	c_open_long_desc = str;
}

string query_c_long(string str)
{
	object *inv;
	int i;
	mixed desc;

	if (this_object()->receive_objects()) desc = c_open_long_desc;
		else desc = c_closed_long_desc ;
	if ((int)query("lock")>0)
	    desc += "���������ġ�\n" ;
	else if  ( ! this_object()->receive_objects() )
		desc += "���ǹ����ġ�\n" ;
	if ((int)this_object()->receive_objects() || (int)this_object()->clear())	{
		inv = all_inventory(this_object());
		if (sizeof(inv) > 0 ) {
			desc += "������:\n";
			for(i=0; i<sizeof(inv); i++)
				desc += sprintf("  %s (%s).\n", (string)inv[i]->query("short"), (string)inv[i]->query("name"));
		}
	}
	return desc;
}

int open_container(string str)
{
 
	//	Check to see if the user can actually see anything.
	if(!this_player()->query("vision"))
		return notify_fail("Open what?  You can't see anything!\n");
 
	if (stringp(str) && this_object()->id(str)) {
		if (this_object()->receive_objects()) write("It is already open.\n");
		else {
			if ((int)query("lock")>0) {
				write ("It's locked!\n") ;
				return 1 ;
			}
			this_object()->toggle_closed();
			write("You open "+this_object()->query("short")+".\n");
			say(this_player()->query("cap_name")+
				" opens "+this_object()->query("short")+ ".\n");
		}
		return 1;
	}
	return 0;
}

int close_container(string str)
{
	//	Check to see if the user can see what they are doing.
	if(!this_player()->query("vision"))
		return notify_fail("Close what?  You can't see anything!\n");
 
	if (stringp(str) && this_object()->id(str)) {
		if (!this_object()->receive_objects()) write("It is already closed.\n");
		else if (!this_object()->toggle_closed()) write("It cannot be closed.\n");
		else {
			write("You close "+this_object()->query("short")+".\n");
			say(this_player()->query("cap_name")+" closes "+
				this_object()->query("short")+".\n");
		}
		return 1;
	}
	return 0;
}

void set_possible_to_close(int pos)
{
    possible_to_close = pos;
}

int toggle_closed()
{
    if (possible_to_close) {
      if (is_closed) is_closed = 0;
      else is_closed = 1;
      return 1;
    }
    else return 0;
}

void to_set_closed()
{
    if ( query("lock") )  is_closed=1;
}

int query_is_closed()
{
	return is_closed ;
}


// This function is called from move()

int receive_objects()
{
    if (is_closed) return 0;
    return 1;
}

/* EOF */

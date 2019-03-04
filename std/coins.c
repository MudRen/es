//#pragma save_binary

// coins.c 
// The basic money object. 
// Sets the property "money". You can identify coins by checking that property. 
// Created by Mobydick@TMI-2, 8-24-92

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit OBJECT;

string type;
int number;

/* Set_descs() is called whenever the number or type of coins is changed. */

void set_descs()
{
	set_name( type+" coin", to_chinese(type+" coin") );
	set ("id", ({ "coin", "coins", type+" coins", type }) );
	if (number==1) {
		set_short( "һö" + to_chinese(type+" coin"));
		set( "unit", "ö" );
	} else {
		set_short("һ��" + to_chinese(type+" coin"));
		set( "unit", "��" );
	}
//	set( "weight", number/10 + 1);
	switch( number ) {
		case 1 : {
			set_long( "�¹µ�����һö"
				+to_chinese(type+" coin")+"��\n" );
			break;
		}
		case 2..5 : {
			set_long( "��ö"
				+to_chinese(type+" coin")+"��\n");
			break;
		}
		case 6..15 : {
			set_long(  "��Լʮö���ҵ�"
				+to_chinese(type+" coin")+"��\n");
			break;
		}
		case 16..25 : {
			set_long( "��Լ��ʮö���ҵ�"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 26..35 : {
			set_long( "��ʮö���ҵ�"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 36..65 : {
			set_long( "һС��Լ��ʮö"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 66..85 : {
			set_long( "������ʮ��ö��"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 86..150: {
			set_long("һ��һ��ö���ҵ�"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 151..350 : {
			set_long( "һ��ѳ���һ����ʮö��"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		case 351..750 : {
			set_long( "�������ö������"
				+to_chinese(type+" coin")+"��\n");
			break ;
		}
		default : {
			set_long( "һ����"
				+to_chinese(type+" coin")+"�ѳɵ�Сɽ��\n");
		}
	}
	return;
}

void create()
{
	type = "gold";
	number = 1;
	set_descs();
	set("money",1);
}

void set_type(string str)
{
	if( member_array(str, COIN_TYPES) == -1 ) remove();
	type = str;
	set_descs();
}

void set_number(int num)
{
	if( num<1 ) remove();
	number = num;
//	set( "weight", 0 );
	set_descs();
}

string query_type() { return type ; }

int query_number() { return number ; }

// When coins move we need to do two checks. First, if we just moved into a
// player, put money into his wealth variable and remove this object. Second,
// if our destination has a pile of the same type of coins, increase the
// number of that pile, and remove this object. If neither of these is true,
// then move the object itself.
int move(mixed dest)
{
	string tmp;
	int i;
	object ob;

//	if( (int)dest->query("load") + (int)query("weight") > (int)dest->query("max_load") )
//		return MOVE_TOO_HEAVY;

	if( living(dest) ) {
		dest->credit( type, number );
		remove();
		return MOVE_OK;
	}
	tmp = type + " coins";
	ob = present(tmp, dest);
	if( !ob ) 
		return ::move(dest);
	i = ob->query_number();
	ob->set_number( i+number );
//	dest->add( "weight", number );
	remove();
	return MOVE_OK;
}

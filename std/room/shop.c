//#pragma save_binary

// A basic shop with a basic storeroom.
// Written by Mobydick@TMI-2, 8-25-92

#include <move.h>
#include <mudlib.h>
#include <money.h>
#include <weapons.h>
#include <armors.h>
#include <guilds.h>

inherit ROOM;
inherit COINVALUE;
 object storeroom,centstore;
#define UP_LIMIT 100
#define LOW_LIMIT 50
object init_storeroom();

void create()
{
	seteuid(getuid());
	::create();
	set_short( "A shop", "�̵�" );
	set_long( "You are in a general shop.\n", "�������̵ꡣ\n" );

	/* Force the warehouse to load, if it's not loaded  */
	CENTSTORE->frog();
	storeroom = init_storeroom();
	centstore = find_object(CENTSTORE);
}

void init()
{
	add_action("list", "list");
	add_action("value", "value");
	add_action("buy", "buy");
	add_action("sell", "sell");
	add_action("enter_storeroom", "storeroom");
	add_action("try_items", "try");
}

object init_storeroom()
{
	object *room, stroom;
	int i;

	room = children("/std/shop/storeroom");
	for(i=0; i<sizeof(room); i++) {
		if( (string)room[i]->query("linked_shop")==base_name(this_object()) )
			return room[i];
	}
	stroom = new("/std/shop/storeroom");
	if( stroom ) return stroom;
	else throw( "Shop: Error in loading storeroom.\n" );
}

void convert_value( object ob )
{
	mixed *value;
	int val;

	value = ob->query( "value" );
	if( !value || !pointerp(value) ) {
		ob->delete("value");
		return;
	}
	if( !intp(value[0]) || value[0]==0 || !stringp(value[1]) ) {
		ob->delete("value");
		return;
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	if( val==0 ) val = 1;
	ob->set( "value", ({ val, "silver" }) );
	return;
}

int list(string arg)
{
	int i, number;
	mixed *value;
	mixed *ob;
	string type,list;

	list = "�����������򵽵���:\n";

	/* Objects in local storage */
	ob = all_inventory(storeroom);
	if( arg && arg!="" ) ob = filter_array(ob, "filter_inv", this_object(), arg);
//	ob = unique_array(ob, "query");
	for (i=0; i<sizeof(ob); i++)
	{
		value = ob[i]->query("value");
		if (!value) continue;
		type = value[1];
		number = value[0];
		if (number==0) continue;
			list += sprintf("  %-34s %5d %s\n", ob[i]->query("short")
			+ "(" + ob[i]->query("name") + ")",
			number, to_chinese(type + " coin") );
	}

	/* Objects in central storage */
	ob = all_inventory(centstore);
	if( arg && arg!="" ) ob = filter_array(ob, "filter_inv", this_object(), arg);
	for(i=0; i<sizeof(ob); i++) {
		value = ob[i]->query("value");
		if (!value||sizeof(value)<2) continue;
		   type = (string)value[1] ;
 	 	   number = (int)value[0] ;
 	 	   
		if (number==0) continue;
			list += sprintf("  %-34s %5d %s\n", ob[i]->query("short") + "(" + ob[i]->query("name") + ")"
			, number, to_chinese(type+" coin") );
	}
	this_player()->more(explode(list, "\n"), 0, 1);
	return 1;
}

int filter_inv(object ob, string name)
{
	if( name=="weapons" && !undefinedp(ob->query("weapon_class")) ) return 1;
	if( name=="armors" && !undefinedp(ob->query("armor_class")) ) return 1;
	else return (int)ob->id(name);
}

int buy(string str)
{
	int number, res,skill;
	string type, unit;
	object ob;
	mixed *value;

	/* Look for the object, first in central storage then in local storage. */
	if (!str)
		return notify_fail( "��Ҫ��ʲ�᣿\n");

	ob = present(str, centstore);
	if( !ob ) ob = present(str, storeroom);
	if( !ob )
		return notify_fail( "����û������������\n");

	value = ob->query("value");
	if( !value ) {
		ob->remove();
		return notify_fail( "����������Ӧ�ó��ֵ���....��\n");
	}
	type = value[1];
	number = value[0];
	if( number==0 ) {
		ob->remove();
		return notify_fail( "����������Ӧ�ó��ֵ���....��\n");
	}
	skill = this_player()->query_skill("trading");
	number -= number * random(skill) / 300;
	if ( living(environment(ob) ) )
		return notify_fail("��Ǹ ! ���ֶ����ո������� ...��\n");
	// Check to see if the player has exact change.
	if( this_player()->debit( type, number ) ) {
		// See if the player can carry the object.
		res = ob->move(this_player());
		if( res==MOVE_OK ) {
			if( skill > 0 ) write( "����һ���ּۻ��ۣ�");
			if( !(unit = ob->query("unit")) ) unit = "��";
			write( sprintf("�㻨%dö%s ����һ%s%s��\n",number ,to_chinese(type + " coin"),unit,ob->query("short") ));
			tell_room( this_object(), 
				sprintf("%s����һ%s%s��\n",this_player()->query("c_name"),unit,ob->query("short")),
				this_player());
			return 1 ;
		} else {
			// Give him his money back.
			this_player()->credit( type , number );
			return notify_fail("���Ѿ����������������ˡ�\n");
		}
	}

	return notify_fail("������û�к��ʵ�Ǯ���ܹ�������������\n");
}

int value(string str)
{
	object *ob, obj;
	int i, number;
	string type;
	mixed *value;

	if( !str ) {
		ob = all_inventory(this_player());
		if( !ob )
			return notify_fail("������û�д��κζ�����\n");

		for( i=0; i<sizeof(ob); i++ ) {
			convert_value( ob[i] );
			value = ob[i]->query("value") ;
			if (!value) {
				write(sprintf("%s��ֵǮ��\n",ob[i]->query("short")));
				continue;
			}
			type = value[1];
			number=value[0] * SHOP_SALES_FRAC;
		 	if( number==0 ) {
				write(sprintf("%s��ֵǮ��\n",ob[i]->query("short")));
				continue;
			}

			write(sprintf("%s��ֵ%d��%s  ��\n",ob[i]->query("short") ,number,to_chinese(type+" coin")));
			if( number>1000 )
				write("�����ϰ����ֻԸ��� 1000 �������չ�.....��\n");
		}
		return 1 ;
	}
	obj = present(str,this_player());
	if( !obj )
		return notify_fail(sprintf("������û�н���%s�Ķ�����\n",str));

	convert_value( obj );
	value = obj->query("value");
	if( !value )
		return notify_fail("���������ֵǮ��\n");

	type = value[1];
	number = value[0] * SHOP_SALES_FRAC;
	if( number==0 )
		return notify_fail("���������ֵǮ��\n");

			write(sprintf("%s��ֵ%d��%s  ��\n",obj->query("short") ,number,to_chinese(type+" coin")));
	if( number>1000 )
		write("�����ϰ����ֻԸ��� 1000 �������չ�.....��\n");
	return 1 ;
}

int in_storeroom(object item)
{
    object *items;
    string item_name;
    int i, count, storage;

    items = all_inventory(storeroom)+ all_inventory(centstore);
//    if( !storeroom->query("storage") ) storage = 1;
//    else storage = (int)storeroom->query("storage");
//    if( storage < 1 ) storage = 1;
	storage = 1;
    count = 0;
    if( !sizeof(items) ) return 0;
    item_name = base_name(item);
    if( !item_name ) return 1;
    for( i=0; i<sizeof(items); i++ ) {
      	if( item_name != base_name(items[i]) ) continue;
      	count++;
      	if( count >= storage ) return 1;
    }
    return 0;
}

int sell_ob(object ob)
{
	int will_remove, res, number;
	string type, unit;
	mixed *value ,*rate;

	convert_value(ob);
	value = ob->query("value");
	if( !value ) {
		tell_object(this_player(),
			sprintf("�ϰ�����%s���������ְ�����������Ͱ��\n",ob->query("short")));
		ob->remove();
		return 1;
	}
    number = value[0] ;
	if (!this_object()->query("rating"))
	  number = number * SHOP_SALES_FRAC;
	else {
	  rate = this_object()->query("rating");
	  number = number * rate[0] / rate[1];
	}
	number -= number * ( 75 - (int)this_player()->query_skill("trading") ) / 200;
	if(number>1000) number = 1000;

	type = value[1];
	// check if this item has been in storeroom, remove it. By Kyoko.
	will_remove = 0;
	if( in_storeroom(ob) ) {
	  tell_room( this_object(), 
		sprintf("�ϰ�˵: %s�����Ѿ����ˣ��������ۡ�\n" ,ob->query("short")));
	  number -= number / 4;
	  will_remove = 1;
	}
	if( number < 1 ) number = 1;
	res = ob->move(centstore) ;
	if( res != MOVE_OK )
		return notify_fail( "�Բ����̵겻�չ����ֶ�����\n");

	if ( !this_player()->credit(type, number) ) {
		write("����������������������õ���Ǯ�ҡ�\n");
		ob->move(this_player());
		return 1;
	}
	if( !(unit = ob->query("unit")) ) unit = "��";
	write(sprintf("������%s�����%d��%s ��\n",
		ob->query("short"),number,to_chinese(type+" coin")));
	tell_room( this_object(), 
		sprintf("%s����һ%s%s��\n",
		this_player()->query("c_name"),unit,ob->query("short")),this_player() );

    if(ob->query("on_mounted")) ob->delete("on_mounted");
    
    if( will_remove ) {
      tell_room( this_object(), 
                sprintf("�ϰ�ܲ���Ը�İ�%s���²�����ǽ�ǡ�\n" ,ob->query("short")));
		ob->remove();
	} else if( ob->query("useless") ) {
		tell_room( this_object(),
			sprintf("�ϰ��%s����ǽ�ǣ����վɻ��������չ���\n" ,ob->query("short")));
		ob->remove();
	}
	else if( ob->query("no_sale") ) {
		tell_room( this_object(), 
			sprintf("�ϰ��%s�ս����Ȼ������Ц��Ц��\n" ,ob->query("short")));
		ob->remove();
	}
	
	return 1;
}
void check_stock()
{
	object *obs;
	int i;
// if items in shop too much .. clear it autoly .. by Ruby
	obs = all_inventory(centstore);
	if ( sizeof(obs) > UP_LIMIT )
		for ( i = sizeof(obs)-1 ; i > LOW_LIMIT ; i-- )
			obs[i]->remove();
	return;
}

int sell(string str)
{
	int i;
	object ob, *obs ;

	if (!str) 
		return notify_fail("��Ҫ��ʲ�ᶫ����\n");

	if( str=="all" ) {
		obs = all_inventory(this_player());
		for( i=0; i<sizeof(obs); i++ ) {
			if( obs[i]->query("prevent_drop") || obs[i]->query("secure") )
				continue;
			if(obs[i]->query("wielded") || obs[i]->query("equipped") ) 
				continue;
			sell_ob(obs[i]);
		}
		check_stock();
		return 1;
	} else {
	ob = present(str, this_player());
	if( !ob )
		return notify_fail("��û������������\n");
	if( ob->query("prevent_drop") || ob->query("secure") )
		return notify_fail("�㲻��������������\n");
	sell_ob(ob);
	}
	return 1;
}

int enter_storeroom()
{
	if (!wizardp(this_player())) return 0;
	this_player()->move(centstore);
	write( "�����ϰ岻ע���ʱ����͵͵���������Ĵ����ҡ�\n");
	say( this_player()->query("c_name") + "ͻȻ�����ˡ�\n");
	return 1 ;
}

int try_items( string str )
{
	int skill, need;
	string type, aclass;
	object ob, guild_ob, me;

	/* Look for the object, first in central storage then in local storage. */
	if( !str )
		return notify_fail("��Ҫ��ʲ�᣿\n");

	me = this_player();
	ob = present(str, centstore);
	if( !ob ) ob = present(str, storeroom);
	if( !ob )
		return notify_fail("����û������������\n");
	write(sprintf("������%s������һ�� .... \n%s",
		ob->query("short"),ob->query("long") ));

	if( !(need = (int)ob->query("weapon_class")) ) {
		// it's a armor?
		if( ob->query("armor_class") || ob->query("defense_bonus") ) {
			type = (string)ob->query("type");
			if( !type || type == "" || member_array(type, ARMOR_TYPES) == -1 ) 
				return notify_fail("����������Ӧ�ó��ֵ���....��\n");
		// not a weapon nor a armor, it's sure he can use.
		} else {
			tell_room( this_object(), 
			sprintf("%s��%s��������������¶�������Ц�ݡ�\n" 
				,me->query("c_name"),ob->query("short")),me );
       		write("�ⶫ��ֻҪ���õĶ�������𣬾Ϳ����á�\n" );
         	return 1;
		}
		// check equip level, defined in guild object.
		aclass = (string)me->query("class");
		if( member_array(aclass, CLASS_NAMES) == -1 ||
		(int)GUILD_MASTER(aclass)->equip_level(ob) > 1 ) {
		tell_room( this_object(), 
			sprintf("%s��%s�������Դ���һ����������ܲ����ʡ�\n", 
				me->query("c_name"),ob->query("short")),me );
			write("�⻤�߾������õĶ��������Ӳ�ǰ����������ƺ������ж��Ч����\n" );
		} else if( (int)GUILD_MASTER(aclass)->equip_level(ob) == 1 ) {
			tell_room( this_object(), 
				sprintf("%s��%s�������Դ���һ�����ƺ���ǿ�ܹ����ϡ�\n", 
				me->query("c_name"),ob->query("short")),me );
			write("�⻤�߾������õĶ�������𣬴������ƺ���Щ��ǿ��\n" );
 		} else {
	     	tell_room( this_object(), 
                sprintf("%s��%s�������Դ���һ�����ƺ��ǳ�����\n",
			me->query("c_name"),ob->query("short")),me );
           	write("�⻤��ֻҪ���õĶ�������𣬾��ܹ�����\n" );
		}
		return 1;
    }
    // It's a weapon.
    type = (string)ob->query("type");
    if( !type || type == "" || member_array(type, WEAPON_TYPES) == -1 ) 
     	 return notify_fail("����������Ӧ�ó��ֵ���....��\n");
	skill = me->query_skill(type);
    if( need <= 15 || skill >= need*2 ) {
       	tell_room( this_object(), 
		sprintf("%s��%s��������������¶�������Ц�ݡ�\n",
			me->query("c_name"),ob->query("short")), me );
       write("����������Լ�Ԧ����������ֻҪ���õĶ�������𣬾Ϳ����á�\n" );
    } else if( (need*2 - skill) < 10 ) {
      	tell_room( this_object(), 
 		sprintf("%s��%s�����������Խ���ƺ��е����ѡ�\n",
			me->query("c_name"),ob->query("short")), me );
 	write("�ټӰѾ����ⶫ����Ϳ����ʹ����!\n" );
    } else {
      	tell_room( this_object(), 
		sprintf("%s��%s�����������Խ���ƺ�ʮ�����ѡ�\n",
			me->query("c_name"),ob->query("short")), me );
      	write("��ɵ�ˣ�����ʮ��������!\n" );
    }
    return 1;
}

object storeroom() { return storeroom; }

void clean_up() { return 0; }

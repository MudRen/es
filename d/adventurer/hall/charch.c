//#pragma save_binary

// A basic holder.
// Written by MO, Qun, Jan 26, 1998 

#include <move.h>
#include <mudlib.h>
#include <money.h>
#include <weapons.h>
#include <armors.h>
#include <guilds.h>

inherit ROOM;
inherit COINVALUE;

#define	MAX_ITEMS	10	//
#define	DIGITS	( { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" } )  //
#define	REM_ITEM_PROP	"rem_item"
#define REM_ITEM_PROP_	REM_ITEM_PROP+"_"	
#define	REM_TIME_PROP	"rem_time"
#define	REM_UPTIME_PROP	"rem_uptime"

//#define UP_LIMIT 100
//#define LOW_LIMIT 50

void create()
{
//	seteuid(getuid());
	::create();
	set_short( "����" );
	set_long( 
	"����һ��Ϊ�Ը������¸Ͻ��Ľ���, �Ĵ��ɼ�ש�ߵĺۼ�, Ҳ�������\n"
	"��������(pray)��\n" );
	set( "light", 1 );
	set( "exits", ( [ "southdown": "/d/adventurer/hall/adv_guild"
	]) );

	/* Force the warehouse to load, if it's not loaded  */
//	CENTSTORE->frog();
//	storeroom = init_storeroom();
//	centstore = find_object(CENTSTORE);
	reset();
}

void init()
{
//	add_action("list", "list");
        add_action("pray", "pray");
//	add_action("remember", "remember");
//	add_action("value", "value");
//	add_action("buy", "buy");
//	add_action("sell", "sell");
//	add_action("enter_storeroom", "storeroom");
//	add_action("try_items", "try");
}

int remember()
{
	object me, *obs;
	int i, j;

	me = this_player();
	obs = all_inventory( me );
	j = sizeof(obs);
	if ( j > MAX_ITEMS )
	    return notify_fail("�����ϵĶ���̫���ˡ�\n");

	me->set( REM_ITEM_PROP, j );
	me->set( REM_TIME_PROP, time() );
	me->set( REM_UPTIME_PROP, uptime() );
	for( i=0; i<j; i++ )
	    me->set( REM_ITEM_PROP_+DIGITS[i], base_name( file_name(obs[i]) ) );

//	command( "save", me );
	tell_object( me, "����д���һ�����������: ����, �Ҽ�ס�ˡ�\n" );
	return 1;
}

int back()
{
	object me, ob, *obs;
	string item_name;
	int i, j, k, m, flag, time1, time2, uptime1, uptime2;

	me = this_player();
	time2 = time(); uptime2 = uptime();
	time1 = me->query( REM_TIME_PROP );
	uptime1 = me->query( REM_UPTIME_PROP );
	i = time2 - time1;
	j = uptime2 - uptime1;
	if ( i < j + 8 && !wizardp(me) )
	    return notify_fail( "��û����, �㼱ʲô? \n" );

	obs = all_inventory(me);
	j = me->query( REM_ITEM_PROP );
	k = sizeof(obs);
	for ( i = 0; i < j; i ++ )
	{
	    ob = new(  me->query( REM_ITEM_PROP_+DIGITS[i] ) );
	    item_name = base_name(ob);
	    for ( m = 0, flag = 0; m < k; m++ )
		if (  item_name == base_name( obs[m] )  )
		    flag = 1;
	    if ( flag == 0 )
		ob->move( me );
	    else
		ob->remove();
	}
	if ( !wizardp(me) )
	    me->set( REM_ITEM_PROP, 0 );
	tell_object( me, "��Ʒ�ָ���ϡ� \n" );	
	return 1;
}

int pray( string str )
{
	if ( this_player()->query( "age" ) < 6*43200 ) // 3 years old?
	    return notify_fail( "�����̫С, ��Ҫ��Ŀ����!\n");
	switch ( str ) {
	    case "remember": return remember();
	    case "back" : return back();
	    default : return notify_fail( 
	"������۾���ʼ�ϵ���, ��Щʲô��, remember ���� back?\n" );
	};
}


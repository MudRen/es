
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

#define MAX_ITEMS       5      //
#define DIGITS  ( { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" } )  //
#define REM_ITEM_PROP   "pray_item"
#define REM_ITEM_PROP_  REM_ITEM_PROP+"_"       
#define REM_TIME_PROP   "rem_time"
#define REM_UPTIME_PROP "rem_uptime"


void create()
{
//      seteuid(getuid());
        ::create();
        set_short( "����" );
        set_long( 
        "����һ��Ϊ�Ը������¸Ͻ��Ľ���, �Ĵ��ɼ�ש�ߵĺۼ�, Ҳ�������\n"
        "��������(pray)��\n" );
        set( "light", 1 );
        set( "exits", ( [ "west": "/d/noden/farwind/cemetery"
        ]) );

        /* Force the warehouse to load, if it's not loaded  */
        reset();
}

void init()
{
        add_action("pray", "pray");

}

int remember()
{
        object me, *obs;
        int i, j;

        me = this_player();
        obs = all_inventory( me );
        j=0;
        for(i=0;i<sizeof(obs);i++)
           if(obs[i]->query("prevent_drop") || !obs[i]->query("value")
                  || obs[i]->query("value")[0]<=0 ) continue;
                  else j++;
           
        if ( j > MAX_ITEMS )
            return notify_fail("�����ϵĶ���̫���ˡ�\n");
        
        me->set( REM_ITEM_PROP, j );
        me->set( REM_TIME_PROP, time() );
        me->set( REM_UPTIME_PROP, uptime() );
        j=0;
        for( i=0; i<sizeof(obs); i++ )
        
           if(obs[i]->query("prevent_drop") || !obs[i]->query("value")
                  || obs[i]->query("value")[0]<=0 ) continue;

           else
           {
             me->set( REM_ITEM_PROP_+DIGITS[j], base_name( file_name(obs[i]) ) );
             j++;
           }

        tell_object( me, "����д���һ�����������: ����, �Ҽ�ס�ˡ�\n" );
        return 1;
}

int back()
{
        object me, ob ;
        string item_name;
        int i, j, m, time1, time2, uptime1, uptime2;

        me = this_player();
        time2 = time(); uptime2 = uptime();
        time1 = me->query( REM_TIME_PROP );
        uptime1 = me->query( REM_UPTIME_PROP );
        i = time2 - time1;
        j = uptime2 - uptime1;
        if ( i < j + 8 && !wizardp(me) )
            return notify_fail( "��û����, �㼱ʲô? \n" );

        j = me->query( REM_ITEM_PROP );
        for ( i = 0; i < j; i ++ )
        {
            ob = new(  me->query( REM_ITEM_PROP_+DIGITS[i] ) );
            me->delete(REM_ITEM_PROP_+DIGITS[i]);
            if(ob->query("prevent_drop") || !ob->query("value")
                  || ob->query("value")[0]<=0 ) 
                ob->remove();
            else
                ob->move( me );
        }
        tell_object( me, "��Ʒ�ָ���ϡ� \n" ); 
        return 1;
}

int pray( string str )
{
        if ( this_player()->query_level() < 17 ) 
            return notify_fail( "��ȼ�̫��, û��������!\n");
        switch ( str ) {
            case "remember": return remember();
            case "back" : return back();
            default : return notify_fail( 
        "������۾���ʼ�ϵ���, ��Щʲô��, remember ���� back?\n" );
        };
}

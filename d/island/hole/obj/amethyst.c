//#include <mudlib.h>
#include <daemons.h>
#include "../hole.h"

inherit OBJECT;

void create()
{
	set_name( "Amethyst","��ˮ��" );
	add( "id",({ "amethyst" }) );
	set_short( "��ˮ��" );
	set_long(@LONG
	һ��������������ˮ������˵��������������
	��â��������ħ�����������������ʹ������
	Ʒ�ϡ�
LONG
		);
	set( "weight",5 );
	set( "no_sale",1 );
	set( "value",({ 320,"silver" }) );
	set( "prevent_drop",1 );
	set( "unit","��");
	set( "light",1 );
}           

void init()
{
	add_action( "to_show","show" );
}

int to_show( string arg )
{
    string who,month,msg;
    object ob;
    int year,day,j,k;
    
    if( !arg ) return notify_fail( "ɶ��\n" );
    if( sscanf( arg, "amethyst to %s", who )!=1 )
      return notify_fail( "Usage : show what to whom\n" );
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(),"����û����ˡ�\n");
      return 1;
    }
    sscanf(WEATHER_D->query_c_game_time(),"������ %d �꣬%s %d �գ�%s %d ʱ %d ��",
    year,month,day,msg,j,k );
    if( msg=="�賿" || msg=="��ҹ" || msg=="ҹ��" ){
    if( undefinedp(ob->change(ob, this_player())) )
    tell_object( this_player(),
	ob->query("c_name")+"˵�����ʲ��?\n" );
    return 1;
    }
    else {
    return notify_fail( "ʱ�䲻��ร�ֻ�н����¹���ܷ������Ĺ��á�\n" );
    }
}

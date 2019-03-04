#include "../island.h"

inherit WEAPON;
void create()
{
	set_name( "personal sword","���õ��佣" );
	add( "id",({ "sword" }) );
	set_short( "���õ��佣" );
	set_long(@LONG
����Ϊ�������佣��������Ҫ�����Կ��Ʋ����֣��Ͽ���������ȥ�ɣ�	
LONG
	);
	set( "unit","��" );
	set( "type","longblade" );
	set( "weapon_class",1 );
	set( "min_damage",1);
	set( "nosecond" , 1);
	set( "max_damage",2 );
	set( "weight",120 );
	set( "value",({ 2500,"silver" }) );
	set( "wield_func","wield_sword" );
	set( "prevent_drop" , 1 );
}

void wield_sword()
{       string name;
	int lv,j,hood,wc1,ski,wc,maxd,mind;
	name=this_player()->query("c_name");
	lv=this_player()->query_level();
	ski=((int)this_player()->query_skill( "longblade" ))/2;
	hood=this_player()->query( "knighthood" );
	switch(hood)
	{
	case "baron":
			j=220;
	 		break;
	case "vicomte":
	 		j=240;
	 		break;
	case "earl":
	 		j=260;
	 		break;
	case "marquess":
	 		j=280;
	 		break;
	case "duke":
	 		j=300;
	 		break;
	case "lord":
	                j=350;
	                break;
	case "overlord":
			j=400;
			break;		                 		
	 }
	 
	wc = ((lv-4)*j)/100 ;
	if ( wc > ski )
	{
	    wc1 = ski;
        }
        else
        {
            wc1 = wc;
        }    
        maxd =  ( wc1*1.25 ) ;
        mind =  ( wc1/1.4 ) ;
	set_short("@@short");
	set_long("@@long");
        set( "weapon_class", wc1 );
        set( "min_damage", maxd );
        set( "max_damage",mind );
	set( "no_sale",1 );
	set( "prevent_drop",1 );
        tell_room( environment(this_player()),
        name+"���佣��������һ�ӣ�����¶����������顣\n",this_player());
        tell_object(this_player(),"������ѽ����⼫�ˣ�����������һ�Ѻ�������Ľ�����\n");
        set_name( "personal sword","@@short" );
	return ;
}
string short()
{   
   string name;
   
   name = this_player() ->query( "c_name" );
   return set_color( name+"���佣", "HIY" );
   
}   
   
string long()
{   
   string str;
   str = " \n�������ר���佣��Ҫ�úð�ϧ�����Ͼ��������������ݰ���\n";
   return str;
}   
    
   
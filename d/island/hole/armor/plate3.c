#include <../hole.h>

inherit ARMOR;
void create()
{
        set_name( "@@name","����ս��" );
        add( "id", ({ "plate" }) );
        set_short( "@@short" );
        set_long(@LONG
	����һ����ǹ����Ŀ��ף���˵�ǵ���а��ɱ
	�˻��������û��������ϵ���Ƭ��Ͻ��˿��
	�ɵġ�
LONG
        );
        set( "unit","��" );
        set( "type","body" );
        set( "material","knight" );
        set( "armor_class",25 );
        set( "special_defense",([ "evil":20,"cold":30 ]) );
        set( "weight",170 );
        set( "value",({ 220,"gold" }) );
        set( "no_sale",1 );
        set( "equip_func","equip_plate" );
        set( "unequip_func","unequip_plate" );        
}

string name(){ return set_color( "Fire Plate","HIR" ); }
string short(){ return set_color( "����ս��","HIR" ); }

void equip_plate()
{
	string cla,him,bonus;
	object player,env;
	int AC;
	
	player=this_player();
	env=environment(player);
	AC = (int)player->query_level()*2+2;
	bonus=player->query( "knighthood" );
	him=player->query( "c_name" );
	cla=player->query( "class" );
	if( cla!="knight" ) {
		tell_object(player,"\nֻ��սʿ���ܷ�����������Ч�á�\n\n");
		tell_room(env,"\n\n��Ȼ����һ�������ζ����֪����˭�ڿ��⡣\n\n"
		"��ѭ����ζ��ȥ....ԭ����"+him+"���ϵ�ë����Ƥ��ȫ�������ˡ�\n\n",player);
	}
	else{
		tell_room(env,"\n\n�㿴��"+him+"���ϡ�����ս�ס��ᣬ˫�۳�����\n"
		"ȫ��ɢ����һ��а�����Ϣ���ݷ�������������\n\n",player);
		tell_object(player,"\n\n��Ȼһ�����ε������������㣬����������������ޱȣ�\n"
		"�ݷ��й�����Ҫ����������塣\n\n");
	        set( "armor_class",AC );
	        switch(bonus){
		 	case "baron":
		 		set( "defense_bonus",2 );
		 		return ;
		 		break;
		 	case "vicomte":
		 		set( "defense_bonus",4 );
		 		return ;
		 		break;
		 	case "earl":
		 		set( "defense_bonus",6 );
		 		return ;
		 		break;
		 	case "marquess":
		 		set( "defense_bonus",8 );
		 		return ;
		 		break;
		 	case "duke":
		 		set( "defense_bonus",10 );
		 		return ;
		 		break;
		}
         return ;
        }
        return ;
}

void unequip_plate()
{
	set( "armor_class",25 );
	delete( "defense_bonus" );
	return ;
}
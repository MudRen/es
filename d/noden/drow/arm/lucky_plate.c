#include "../iigima.h"

inherit ARMOR;

void create()
{
        set_name("Lucky plate","��������");
        add("id",({"plate"}) );
         set_short( "��������");
	set_long(@C_LONG
����һ���п���С��ͼ�Ƶ��������ס���ڶ����ܷ���
������֤�����������ĳЩ�ں�ҹ�л���˵�װ����
����ʵ��൱���ɣ����̲�ס�봩������
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 145 );
	set( "type", "body" );
	set( "material", "thief");
	set( "armor_class", 18 );
        set( "defense_bonus",0 );
	set( "value", ({ 330, "gold" }) );
        set( "equip_func","wield_plate" );
        set( "unequip_func","unwield_plate" );        
}

void wield_plate()
{
        string cla,him,bonus;
        object player,env;
        player=this_player();
        env=environment(player);
        him=player->query( "c_name" );
        cla=player->query( "class" );
         if( cla!="thief" ) {
                tell_object(player,"\nһ��а���������ڷ��������������졣\n\n");
 tell_room(env,"\n\n�㿴��"+him+"�Źֵ�����üͷ��Ť������������̴�....\n\n");
 }
        else{
tell_room(env,
   "\n\n�㿴��"+him+"�������������ᣬ���ֵ��Թ��Ը��������裬�����е��㶷..\n\n",player);         
tell_object(player,
"\n\n��Ȼһ�����������ĸо��������ķ��������㲻�������赸һ��\n\n");
                set( "armor_class",30 );
                set("defense_bonus","@@lucky_bonus");
         return ;
        }
        return ;
}
void unwield_plate()
{
        set( "armor_class",18 );
        delete( "defense_bonus" );
        return ;
}
int lucky_bonus()
{ 
   return 4 + random(4);
}     

#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("Sky eye", "����֮��");
        add( "id", ({ "eye","sky" }) );
        set_short("����֮��");
        set_long(@C_LONG
�㿴��һ��������Ķ�����ɢ����һƬ����ɫ�����ů�Ĺ�ã�� 
���ഫ�ǵز�����������а����У���������������������̾Ϣ���û��ɵġ� 
���ķ����������ߣ����ഫ�����������п�����ò�ʵ��Ʒ֮������ 
C_LONG
                   );
        set("unit","��");
        set( "type", "head" );
        set( "material", "wood");
        set( "armor_class", 1 );
        set( "defense_bonus", 2 );
	set( "equip_func", "angel" );
	set( "unequip_func", "ruby" );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":1 ]) );
        set( "weight", 10 );
        set( "value", ({ 10, "gold" }) );
} 

void angel()
{
int ali; 
object holder;

 holder = environment(this_object());
 ali=(int)holder->query("alignment");
 if (ali < 1500) {

     tell_object( holder, 
     "\n\n����ͻȻ���һ���â�����ƺ���Ը������㣬�ĵ�һ�����ڵ���... 
   \n"); 
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, 
 "\n�����ܵ����񣬴͸���λ�������˿�����ò�ʵ�����������!!!��
�����Ǳ����ˣ�ҪΪ����͹������Ͱ�!������ɢ��������ɫ�Ĺ��\n"
     ); 
	holder->set_temp("detect_invi",1);
            }   
}

void ruby()
{
object holder;

 holder = environment(this_object());


    tell_object( holder, 
 "\n
�������ˣ�����ҪΪ����͹������Ͱ�!������ָ���ԭ���ĵ���ɫ\n"
     ); 
	holder->set_temp("detect_invi",0);
}

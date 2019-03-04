#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;

void init()
{
	add_action( "eat_food", "drink_me" );
}

void create()
{
        
	set_name("Sugar Swallow-Nest","���������ѡ�");
	add( "id" , ({ "nest","sugar swallow-nest" }) );
        set_short(set_color("���������ѡ�","HIY"));
        set_long(@C_LONG
һ�뾫�ĵ��ƵĲ�Ʒ���ţ�������(drink_me nest)���������������ˬ��
C_LONG
	);
   	set("unit","��");
   	set("weight", 50);
   	set("value",({ 450, "gold" }) );
}

int eat_food(string arg)
{
        
    if( !arg || ( arg != "nest") && ( arg != "sugar swallow-nest" ) ) {
        tell_object(this_player(),"���� ( drink_me nest )��\n");
        return 1;
    }
    this_player()->add_temp("drink_nest_times",1);
    if( this_player()->query_temp("drink_nest_times")>5 ) {
       tell_object(this_player(),
         "Ӵѽ�����������һ��"+set_color("���������ѡ�","HIY")+"֮����ò���Ծ��������ǲ���ͷ�ˡ���\n");
       tell_room( environment(this_player()),"Ӵѽ��"+
         this_player()->query("c_name")+
         "��һ��"+set_color("���������ѡ�","HIY")+"֮�Ὺʼ�е�ֵֹģ������ǲ���ͷ�ˡ���\n",
         this_player());
       this_player()->delete_temp("drink_nest_times");
       CONFUSED->apply_effect(this_player(),20,1);    
       remove();
       return 1;
    }
    tell_room( environment(this_player()),"��վ���Ա�����ˮ�ؿ���"+
        this_player()->query("c_name")+"����һ��"+set_color("���������ѡ�","HIY")+"����\n", 
         this_player());
    tell_object( this_player(),
        "������غ���һ��"+set_color("���������ѡ�","HIY")+"���ţ��úȡ���\n");
    this_player()->set("hit_points",this_player()->query("max_hp"));
    this_player()->set("spell_points",this_player()->query("max_sp"));
    remove();
    return 1;
}

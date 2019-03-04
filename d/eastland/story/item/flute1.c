#include "../story.h"
#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define CNAME(x) (string)x->query("c_name")

inherit OBJECT;
void create()     
{
	set("short", "@@query_short");
	set("long",@LONG
���ǡ������塹֮��������֮�ѣ����ܴ�������춼(cast-me)��
LONG
);
 	set_name( "fly flute", "����֮��" );
        add("id",({"flute"}));
	set( "unit", "��" );
	set("weight", 40);
	set("value", ({ 100, "silver" }));
}
void init()
{
	add_action("cast_me", "cast-me");
}
void sent(object traveller,string target,string msg)
{
    tell_object(traveller,set_color(msg,"HIW"));
    traveller->move_player(target,"SNEAK");
} 
int who_in_party(object obj, string me)
{
     if( !living(obj) ) return 0;
     if( LEADER(obj)!= me ) return 0;
        return 1;
}
int cast_me(string arg)
{
     object player,env,*party;
     string target,msg;     
     int i;
     player=environment(this_object());
     if ( !living(player) )
        return notify_fail("���������ʹ�á�\n");
     if ( !query("flute_left") )
        return notify_fail("�˷���֮�ѵ���Դ�Ѿ��þ��ˡ�\n");
     env=environment(player);
     if ( !env->query("can_use_flute") )
        return notify_fail("���޷�������ط�ʹ�÷���֮�ѣ�\n");
     tell_object(player,set_color(
        "\n�����еġ�����֮�ѡ����������˵���������˸�����⣬���ҳ����˾޴��˫��\n\n","HIW"));
     tell_room(env,set_color(sprintf(
        "\n%s���еġ�����֮�ѡ����������˵���������˸�����⣬���ҳ����˾޴��˫��\n\n",
        CNAME(player)),"HIW"),player);
     if ( env->query("goto_palace") ) {
       target=SPALACE"plain1";
       msg="һ����۵�����֮�ᣬ������֮�ѡ�����������춼��\n\n";
     }
     else {
        target=SAREA"mountain2";   
        msg="һ����۵�����֮�ᣬ������֮�ѡ�������뿪���춼��\n\n";
     }
     if (!LEADER(player)||LEADER(player)!=NAME(player)) {
         sent(player,target,msg);
         return 1;    
     } 
     party=filter_array(all_inventory(env),"who_in_party",this_object(),NAME(player));
     for (i=0;i<sizeof(party);i++) 
        sent(party[i],target,msg);                                
     return 1;
}

string query_short()
{
     return sprintf("����֮��%s", (!query("flute_left") ? " (��Դ�ľ�)" : "") );
}


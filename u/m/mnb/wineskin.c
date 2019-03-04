#include <mudlib.h>

inherit OBJECT;
int num;
void create()
{
        set_name("wineskin","ţƤ�ƴ�");
        add( "id", ({ "skin" }) );
        set_short("�ƴ�");
        set( "weight", 10);
        set( "value", ({ 0, "coin" }));
        set("long", "@@query_desc");
        set("unit", "��");
        set("no_sale",1);
        num=100;
}

void init()
{
        add_action("to_drink","drink");
}

string query_desc()
{
        if(num>=100) return "һ��װ���Ƶ�ţƤ�ƴ�\n";
        if(num<100 && num >=70) return "һ���ߡ��˳�����ţƤ�ƴ�\n";
        if(num<70 && num >=40) return "һ��������ţƤ�ƴ�\n";
        if(num<40 && num >0)   return "һ��װ��һЩ�Ƶ�ţƤ�ƴ�\n";
        if(num<=0) return "һ�����˵�ţƤ�ƴ�\n";
}
int to_drink(string arg)
{
        object me;
        int maxhp,maxsp,maxtp,maxfp;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
        {
                tell_object(me,
                "�����ʲô?\n"
                );
        }
        else 
        {
                if(num<=0) 
                {
                   tell_object(me,
                   "��һ��ͷ����Ⱦ�, ȴ���־ƴ��ѿ���...\n");
                   tell_object(me,
                   "�����ðѾƴ�˺������ ! \n");
                   this_object()->remove();
                   return 1;
                }
                num--;
                tell_object(this_player(),
                "��һ��ͷ,���๾��غ��˼��ھ�.\n");
        
        tell_room( environment( me ),
                me->query("c_name")+"һ��ͷ,���๾��غ��˼��ھƣ�\n"
                , me);

        maxhp = (int)me->query("max_hp");
        maxsp = (int)me->query("max_sp");
        maxtp = (int)me->query("max_tp");                            
        maxfp = (int)me->query("max_fp");
                
        me->add("force_points",5);
        if ((int)me->query("force_points") >= maxfp)
        {
                me->set("force_points" , maxfp);
        }
                        
        me->add("hit_points", 5);
        if ((int)me->query("hit_points") >= maxhp) 
        {
                me->set("hit_points",maxhp) ;
        }
        
        me->add("spell_points", 5);
        if ((int)me->query("spell_points") >= maxsp) 
        {
                me->set("spell_points",maxsp) ;
        }
        
        me->add("talk_points", 5);
        if ((int)me->query("talk_points") >= maxtp) 
        {
                me->set("talk_points",maxtp) ;
        }
        
        }
        return 1;
}

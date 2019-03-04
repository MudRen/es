#include <mudlib.h>

inherit WEAPON;

string C_NAME=("���֮��");
void create()
{
        set_name( "Sky Sword",C_NAME );
        add( "id",({ "sword","sky","sky sword" }) );
        set_short( C_NAME );
        set_long(@LONG
���֮���������������ഫ��ʥ������쳣���������л����׵���ʥ������
��ͼȾָ���֮�ǵ�����սʿѪ�������߲���ʤ����
LONG
                );
        set( "unit","��" );
        set( "type","longblade" );
        set( "weapon_class",35 );
        set( "min_damage",18 );
        set( "max_damage",35 );
        set( "weight",130 );
        set( "value",({ 1200,"silver" }) );
        set( "second",0 );
        set( "prevent_insert",1 );
        set( "hit_func","hit_fun" );
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int hit_fun(object victim,int dis)
{
        object holder;
        string guild;
        int dam,skill,point1,point2,rate,hp,sp;
        string name1,name2;

        if( !victim ) return 0;
        if( !(holder=environment( this_object() )) || !living(holder) ) return 0;
        skill=(int)holder->query_skill("longblade");
        name1=holder->query("c_name");
        name2=victim->query("c_name");
        hp = (int)holder->query("hit_points");
        sp = (int)holder->query("spell_points");
        point1=holder->query_perm_stat("int");
        point2=victim->query_perm_stat("int");
        guild = holder->query("class");
        rate = point1 - point2;
        if (rate > 6) rate = 6;
        if( random(100) < (160 - skill - rate) ) return 0;
        dam = 20 + random(holder->query_skill("ethics")/8);
                // Ҫ���ñ�����ĵ��ƶ������Ч�Ĵ������....:p
                // ��ʵ����ΪĳЩscholar ��������˵������ethics ...�е㲻ˬ
        victim->receive_special_damage( "electric", dam );
        tell_room(environment(victim),"\n"+name1+"���е����֮����Ȼ����һ��"+
                "����ֱ����ʣ�\n��ʱ���Ʊ�ɫ��������һ����������������׼"+
                "�Ĵ���"+name2+"��ͷ�ϣ���������������˺���\n",this_player()
        );
        tell_object(holder,"\n�����еĽ�������"+set_color("����","HIB")
                +"���������׵Ļ�������ĵ��ˣ������"
                +set_color("����������","HIR")+"���ƻ���\n\n" );
        victim->set("last_attacker",holder);
        holder->set("hit_points",hp - 5);
        holder->set("spell_points",sp - 8);
        return dam;
}

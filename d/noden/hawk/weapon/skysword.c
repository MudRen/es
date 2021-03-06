#include <mudlib.h>

inherit WEAPON;

string C_NAME=("天空之剑");
void create()
{
        set_name( "Sky Sword",C_NAME );
        add( "id",({ "sword","sky","sky sword" }) );
        set_short( C_NAME );
        set_long(@LONG
天空之剑是鸟人族历代相传的圣物，锋利异常，更有著招唤天雷的神圣力量，
意图染指天空之城的蛮族战士血溅其下者不可胜数。
LONG
                );
        set( "unit","把" );
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
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
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
                // 要懂得辨别人心的善恶才能有效的打击敌人....:p
                // 其实是因为某些scholar 自做聪明说不用练ethics ...有点不爽
        victim->receive_special_damage( "electric", dam );
        tell_room(environment(victim),"\n"+name1+"手中的天空之剑忽然发出一道"+
                "闪光直冲天际，\n顿时风云变色，紧接著一道闪电从天而降，精准"+
                "的打在"+name2+"的头上，造成难以言喻的伤害。\n",this_player()
        );
        tell_object(holder,"\n你手中的剑呼唤出"+set_color("雷神","HIB")
                +"的力量彻底的击溃了你的敌人，造成了"
                +set_color("「难以想像」","HIR")+"的破坏！\n\n" );
        victim->set("last_attacker",holder);
        holder->set("hit_points",hp - 5);
        holder->set("spell_points",sp - 8);
        return dam;
}

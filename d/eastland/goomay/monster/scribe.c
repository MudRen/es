#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Hsin the scribe", "邢师爷" );
        add( "id", ({ "scribe","hsin" }) );
        set_short( "邢师爷" );
        set_long(
@LONG
邢师爷留了两撇稀稀疏疏的小胡子，穿著一身青衫，他本来是一位私塾老师
由於他对於衙门的一切文书往来十分内行，因此被现任县太爷(magistrate)
重用，他是一个好好先生，只要不是什麽杀人放火的大罪，到了他手上总会
有机会翻身，他是一个值得托付的人。
LONG
        );
        set( "gender", "male" );
	set("race","elf");
	set( "alignment",600);
        set_natural_armor( 40, 10 );
        set_natural_weapon( 13, 9, 16 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set_skill( "target",80);
        set_skill( "concentrate",80);
        set_skill( "elemental",80);

        set( "tactic_func", "my_tactic" );
        set( "spells/sleet",2);
        set("spell_power",0);

	set( "defense_type","parry");
        set( "hit_points", 250 );
        set( "max_hp", 250 );
	set( "wealth/gold",10);
		set("spell_levels/elemental",15);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
		"magistrate" : "@@ask_magistrate",
        ]) );

}
int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 60 )
                set( "spell_points",query("max_mp"));
        command("cast sleet at "+(string)victim->query("name"));
}

int ask_magistrate()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")> 2)
        {
        tell_object(me,
        "邢师爷道：「谢谢您救了县太爷一命，他现在已经好多了 !!」\n");
        return 1;
	}
        else
        {
        tell_object(me,@C_MAGI
邢师爷道：「县太爷公务繁忙，没有时间见外人，如果没有公务上的需要，他是
不会见你的，有事就由我为你转达吧 !!」
C_MAGI
        );
                return 1;
}
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")>2)
        {
	tell_object(me,
	"邢师爷道：「月神像不是已经找回来了吗？不过还是谢谢您救太爷一命 !!」\n");
	return 1;
	}
        else
        {
        tell_object(me,@C_STATUE
邢师爷道：「嗯 !! 这个嘛 !! 说来话长 ～～ 本来我们已经抓到那个江洋大盗了
不料他狡猾成性，死也不肯把赃物交出来，段捕头用了几次刑他就装死装昏的，後
来太爷只好把他还押候审，不料他居然趁狱卒不备，伙同一个死囚偷偷挖地道逃了
，现在我们正倾全力追捕他们。所以呢 !! 那个月神像就 .. 还要再等一段时间喽」
C_STATUE
        );
                return 1;
}
}

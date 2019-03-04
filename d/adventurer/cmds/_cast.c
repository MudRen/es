//#pragma save_binary
// cast.c
// Command hook for spellcasting.
// A player casts a spell by typing "cast <name> [at|on] <name>"
// The input is parsed for spell name and target, and control is passed
// to /cmds/std/<name>_spell.c, which takes the target as an argument
// and does the Right Thing.
// Many of the spells require hooks in the user object. These hooks are
// found in /std/living/spells.c.
// You can make monsters cast spells also. See /obj/foobird.c or any other
// spellcasting monster's code for the details.

// Created 10-5-92 by Mobydick@TMI-2
// Update by Kyoko.

#include <mudlib.h>
#include "/d/adventurer/magic/magic.h"

#define TP_COST 5

inherit "/d/adventurer/magic/adm/magic";

int spell_exists(string spell);

int help();

int cmd_cast (string str)
{
	string type, targname, spell, code;
	int found, sp_cost, skill, spell_power;
	object target;
	string *known;
	mixed spell_level;

	if( !str ) return help();

	if( (int)this_player()->query_level() <20 )
	        return notify_fail("�㵽���������?\n");
	if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail (
			"( ����һ��������û����ɣ��޷�ʩ���� )\n");

    if( this_player()->query_temp("cast_busy") )
        return notify_fail( 
            "����һ��ħ����û����ɣ��޷�ʩ���� \n");

    if( this_player()->query_temp("slience") ||
        this_player()->query("slience") )
      return notify_fail( 
        "����׼��������ʱ����Ȼ������ͻȻ������������\n" );

    if( environment(this_player())->query_temp("no_cast") ||
        environment(this_player())->query("no_cast") )
      return notify_fail( 
        "һ����ֵ�����ʹ��������ġ�\n" );
    
     if ( sscanf( str, "%s %s at %s",type, spell, targname)==3  ||
          sscanf( str, "%s %s on %s",type, spell, targname)==3 ) {
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if ( undefinedp(spell_level= this_player()->query("spells/"+spell)) )
			return notify_fail ( 
				"�㲻�ǵ������ַ�����\n");

	} else if ( sscanf( str, "%s at %s", spell, targname)==2 || 
		        sscanf( str, "%s on %s", spell, targname)==2 ) {
		type = "";
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if( undefinedp(spell_level= this_player()->query("spells/"+spell) ) )
			return notify_fail (
				"�㲻�����ַ�����\n");
	} else {
		spell = str;
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if ( undefinedp( spell_level= this_player()->query("spells/"+spell) ) )
			return notify_fail( 
				"�㲻�ǵ������ַ�����\n");
		targname = "NONE";
	}
	
	code = MAGIC_D->find_spell( spell );
	if( !code )
		return notify_fail(
			"û�����ַ��� .... ��֪ͨ��ʦ���� bug ָ��淨�����ơ�\n");

    if( !this_player()->query("vision") && targname != "NONE" )
      return notify_fail(
	    "�㿴����Ŀ�꣬����ʩ��!\n" );

if (targname != "NONE") 
{
	target = present(targname, environment(this_player()));
	if (!target) return notify_fail("�����˭ʩ����\n");
	if( (int)target->query("ghost")==1 )
            	    return notify_fail("����������Ѿ����ˣ��㻹��������\n");
}
	if( this_player()->query("weapon1") && ( this_player()->query("weapon2") ||
	     this_player()->query("armor/shield") ) )
	  return notify_fail( 
	    "��û�ճ��κ���ʩ����!\n");

	if( !type || type == "" ) {
//    spell_level -= (int)this_player()->query("spell_power");
	  spell_power = this_player()->query("spell_power");
	  if (spell_power <0)	spell_level += spell_power;
	  if (spell_power >0) 
	    spell_level = (spell_power > spell_level) ? spell_level : spell_power;
	}
    else
      switch( type ) {
        case "max"     : break;
        case "regular" : spell_level -= 1; break;
        case "normal"  : spell_level -= 2; break;
        case "minor"   : spell_level -= 3; break;
        case "mini"    : spell_level -= 4; break;
        default : return notify_fail( 
          "û�����ַ������������� max, regular, normal, minor, mini��\n" );
      }
    if( spell_level < 0 ) spell_level = 0;
	sp_cost = (int)code->query_sp_cost( this_player(), spell_level, targname );
	if (!(this_player()->query("npc")))
	{
	if( sp_cost && (int)this_player()->query("spell_points") < sp_cost )
		return notify_fail("��ķ���������\n");

	if( (int)this_player()->query("talk_points") < TP_COST )
		return notify_fail("��û������������ģ�\n");
	
	if( this_player()->query_attacker() ) {
		skill = this_player()->query_skill("concentrate");
		if( random((sp_cost>100)? 100 : sp_cost) > skill ) {
			write("���޷���Ч���о���\n");

			tell_room( environment(this_player()), 
				this_player()->query("c_name") + "�૵�����һ�����ģ������ƺ��޷�ר�����ꡣ\n",
				this_player() );
			this_player()->add("spell_points", -sp_cost/2);
			this_player()->add("talk_points", -TP_COST);
			return 1;
		}
	}
	}
	
	if( code->cast(spell_level, targname) ) {
	  this_player()->add("spell_points", -sp_cost );
	  this_player()->add("talk_points", -TP_COST);
	}
	return 1;
}

int help()
{
		write( @C_HELP
ָ���ʽ: cast [����] <��������> [on|at] <Ŀ��>

���ָ����������ʩչ����������һ�����еķ�����Ҫָ��Ŀ�꣬��Щ�������
����ѡ��Ŀ�ꡣ������� spells ָ���Ŀǰ�Ѿ�ѧ��ķ����б���������
���ޣ�ûָ������Ŀǰ���趨�ı�׼����Ϊ׼�������spellpowerָ���Ŀǰ
�����ı�׼������������Ϊ max, regular, normal, minor, mini ��

�������ƿ��ü�д����, ���� info slist ָ��ȥ���ĸ������ļ�д��
C_HELP
		);

    return 1;
}

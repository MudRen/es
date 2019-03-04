#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	//object staff, amulet;

	::create();
	//seteuid( getuid() );
	set_level(20);
	set_name( "Retal", "�׶�" );
	add ("id", ({ "retal", "mage","archmage" }) );
	set_short( "Retal the archmage of the Echo city", 
	           "Echo city �Ĵ�ħ��ʿ�׶�" );
	set_long(@LONG
Retal is an old experienced mage.When evil lich,firer,whelmed the 
    echo city ,he was the only man escaped. 
LONG
    ,@C_LONG
        ħ��ʿ�׶���Echo city �Ĵ�ħ��ʦ. ��а��� Lich ������ Echo city
    �����֮��,����Ψһ�ӳ�������.
C_LONG
	);
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 20);
	
	set ("max_hp", 500);
	set ("max_sp", 600);
	set ("hit_points", 500);
	set ("spell_points", 600);
	set ("wealth", ([ "gold": 10 ]) );
	set ("natural_weapon_class1", 20);
	set ("natural_armor_class", 15);
	set ("natural_min_damage1", 15);
	set ("natural_max_damage1", 25);
    set ("weight", 350);
    set ("exp_reward", 30000 );
    //set ("inquiry", ([
    //     "mage" : "@@ask_mage",
    //   "spells" : "@@ask_spells",
    //    ]) );
    
	//staff = new(MOYADA"obj/thunderwand.c");
	//staff->move(this_object());
	//wield_weapon(staff);
    //amulet = new( MOYADA"obj/amulet" );
    //amulet->move(this_object());
    //equip_armor(amulet);
}

//void ask_mage( object who )
//{
//    tell_object( who, can_read_chinese(who) ?
//      "���޵�˵: ��ӭ����ħ��ʦ���ᣬ����������֮�⣬����ʲ�����壬\n"
//      "          ֻҪ��ħ������Ȥ�����ܹ���Ϊ���ǵ�һԱ��\n":
//      "Rashudi says: Welcome to join mage guild. Who is interesting\n"
//      "              in the power of magic is welcome to be a mage\n"
//      "              unless a lizardman.\n"  
//    );
//}

//void relay_message(string class, string msg)
//{
//     string who;
//     object obj;
     
//     if( sscanf( msg, "%s arrives.\n", who )==1 ) {
//       obj = find_player(lower_case(who));
//       if( (string)obj->query("class")=="mage" ) {
//         if( (int)obj->query("alignment")<(-3000) )
//           command("kill "+lower_case(who));
//         else if( (int)obj->query("alignment")<(-2000) )
//           tell_object( obj, can_read_chinese(obj) ?
//             "���޵�˵: �ٴξ����㣬����̫�໵���ˡ�\n":
//             "Rashudi says: Warning! you are too bad!\n" );
//         else if( (int)obj->query("alignment")<(-1000) )
//           tell_object( obj, can_read_chinese(obj) ?
//             "���޵�˵: С�ĵ㣡����̫�໵���ˡ�\n":
//             "Rashudi says: Be careful, don't be too bad!.\n" );
//       }
//     }
//}

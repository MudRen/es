#include <mudlib.h>

inherit ARMOR;

void create()
{
            set_name( "Gods gift","众神的礼赞" );
            add( "id", ({ "gift","gods gift" }) );
            set_short( "众神的礼赞" );
            set_long(@LONG
    这是奥林帕斯山上众神赐与人间最强的防具，唯有具有高度智慧与强大力
量的人才有能力使用它。你仔细端详这件足以覆盖住你全身的宝物，上面所刻
精美绝伦的龙凤纹正是诸神的证明。
LONG );
	set( "armor_class",20 );
	set( "defense_bonus",40);
	set( "type", "misc" );
            set( "equip_func","wear_func");
            set( "unequip_func","unwear_func");
	set( "weight", 120);
            set( "value" ,({ 410, "silver" }) );
}

void wear_func()
{
        string guild;
        guild = this_player()->query( "class" );
        set( "material", guild );
}

void unwear_func()
{
        set( "material", "cloth" );
}

int stop_wear(object player)
{
        player = this_player();

        if ( (player->query("armor/head")) || (player->query("armor/arms"))
          || (player->query("armor/misc")) || (player->query("armor/legs"))
          || (player->query("armor/finger")) )
        {
                write( "你穿了某种和诸神的礼赞相冲突的防具!\n");
                return 1;
        }

        else if ( (int)player->query_perm_stat("int") < 14 )
        {
                write( "诸神认为你是个笨蛋，不愿你糟蹋这个礼物!\n");
                return 1;
        }
        else return 0;
}

void init()
{
        add_action( "do_wear", "wear");
}

int do_wear(string str)
{
        object wea1, wea2, obj, *ob, player, armor;
        string type, verb;
        int i;

        player = this_player();
        armor = this_object();
        obj = present( str, player );

        if ( !str || str == "" ) return 0;

        if ( str == "gift" || str == "gods gift" )
                return stop_wear( player );

        if ( str == "all" )
         {
                ob = all_inventory( player );

                if(!(player->query("armor/head")||player->query("armor/arms")
                  || player->query("armor/misc")||player->query("armor/legs")
                  || player->query("armor/finger") ) )
                 {
                        if ( !armor->query( "equipped" ) )
                         {
                                if ( !stop_wear( player ) )
                                 {
                                        armor->equip();
                                        armor->set( "equipped", 1 );
                                        write( "你顺利地穿上众神的礼赞。\n" );
                                        tell_room( environment(player),
                                                player->query("c_name")
                                                + "利地穿上众神的礼赞。\n",
                                                player );
                                 }
                         }
                 }

                for ( i=0; i<sizeof(ob); i++ )
                 {
                        type = (string)ob[i]->query( "type" );

                        if ( !(ob[i]->query( "armor_class" )
                            || ob[i]->query( "defense_bonus" ) )
                            || ob[i]->query( "equipped" )
                            || player->query( "armor/" + type ) )
                                continue;

                        if ( ob[i] == armor ) continue;
                        if ( player->block_wear( ob[i] ) ) continue;
                        if ( ob[i]->stop_equip( player ) ) continue;

                        if ( type == "head" || type == "arms"
                          || type == "misc" || type == "legs"
                          || type == "finger" )
                         {
                                if ( armor->query( "equipped" ) ) continue;
                         }

                        if ( type == "shield" )
                         {
                                wea1 = player->query( "weapon1" );
                                wea2 = player->query( "weapon2" );

                                if( wea2 ) continue;
                                if( wea1 && (int)wea1->query("nosecond") == 1 )
                                         continue;
                         }

                        switch ( ob[i]->query( "equip_level" ) )
                         {
                                case 0 : verb = "顺利地";   break;
                                case 1 : verb = "勉强地";   break;
                                case 2 : verb = "硬生生地"; break;
                                default : verb = "";        break;
                         }

                        switch ( type )
                         {
                                case "body":
                                case "legs":
                                case "feet":
                                case "cloak": verb += "穿上"; break;
                                case "head":
                                case "finger":
                                case "hands":
                                case "misc": verb += "戴上"; break;
                                case "globe": verb += "张开"; break;
                                case "shield": verb += "用手拿起"; break;
                                case "saddle": verb += "装配上"; break;
                                case "kernel": verb += "吞下"; break;
                                case "arms":
                                case "tail": verb += "套上"; break;
                                default: verb += "穿上"; break;
                         }

                        ob[i]->equip();
                        write( "你" + verb
                               + (string)ob[i]->query("c_name") + "。\n" );
                        tell_room( environment( player ),
                                        (string)player->query( "c_name" )
                                        + verb
                                        + (string)ob[i]->query("c_name")
                                        + "。\n", player );
                 }
                write( "Ok.\n" );
                return 1;
         }

        if ( !obj ) return 0;

        type = obj->query( "type" );

        if ( type == "head" || type == "arms" || type == "misc"
          || type == "legs" || type == "finger" )
         {
                if ( armor->query( "equipped" ) )
                 {
                        write( "你已经穿了同类型的护甲了。\n" );
                        return 1;
                 }
                else return 0;
         }
        else return 0;
}

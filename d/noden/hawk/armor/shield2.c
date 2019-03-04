inherit ARMOR;

void create()
{
        set_name("Heaven shield","ʥ���");
        add( "id", ({ "shield" }) );
        set_short( "ʥ���") ;
        set_long(@LONG
����һֻ����ʫĦ��ʥ��ұұ���Ķ��ƣ��������ǲ��ڻ��£�����Ҫ����ȫ
���ӳ��������������Լ�Ҳ��Ҫ�е������
LONG
        );
        set("unit","��");
        set( "type", "shield" );

        set( "material", "mage");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "no_sell",1);
        set( "weight", 100 );
        set( "equip_func","wear_func");
        set( "unequip_func","unwear_func");
        set( "value", ({ 100, "silver" }) );
}

void wear_func()
{
        if( (int)this_player()->query_level() < 15)
        {
                tell_object( this_player(),
                "��..�����������..�����޷�������õ����Ƶ�����\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",3);
        }

        if( ((int)this_player()->query("spell_levels/guild") < 45)||
          ((int)this_player()->query("spell_levels/black-magic") < 42))
        {
                tell_object( this_player(),
                "���ħ�����˽⻹����..�޷��ö��������ӳ���������\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",6);
                set( "special_defense",
			([ "fire": -15, "evil": 10, "cold": 15,
				"divine": -10, "poison":-15, "energy": 15]));
                write( set_color(
                        "\nʥ��ܺ�Ӧ�����ħ����ɢ��һ�����������������...\n\n"
                        ,"HIW") );
        }
}

void unwear_func()
{
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
}

<?php

/*
* Contains the configuration required for the adpca_custom module
*/

define('ADPCA_CUSTOM_CONFIG_PATH', "/home/adpca/public_html/adpca.rutlidge.com/sites/default/files/adpca_custom");

class ADPCAConstants {
   private static $fields = array(
	"title"			=>	"prefix_id",
	"first_name"		=>	"first_name",
	"middle_name"		=>	"middle_name",
	"last_name"		=>	"last_name",
	"street_addres"		=>	"street_address-Primary",
	"address_1"		=>	"supplemental_address_1-Primary",
	"address_2"		=>	"supplemental_address_2-Primary",
	"city"			=>	"city-Primary",
	"postal_code"		=>	"postal_code-Primary",
	"country"		=>	"country-Primary",
	"state"			=>	"state_province-Primary",
        "phone"			=>	"phone-ext-Primary-1",
	"mobile"		=>	"phone-Primary-2",
	"directory_view"	=>	"custom_1",
	"suppress_mail_address"	=>	"custom_4",
	"do_not_send_journal"	=>	"custom_5",
	"send_hard_copy_newsletter"=>	"custom_6",
	"do_not_email"		=>	"do_not_email",
	"do_not_mail"		=>	"do_not_mail",
	"couple_membership_partner"=>	"custom_7",
	"school_college_name"	=>	"custom_8",
        "graduation_date"	=>	"custom_9");
   private static $cont_forms=array(
	"3"			=>	"membership_individual",
	"4"			=>	"membership_student",
	"5"			=>	"membership_institutional",
	"6"			=>	"membership_supporting",
	"7"			=>	"membership_journal");
   public static function getFields() {
        return self::$fields;
   }
   public static function getForms() {
        return self::$cont_forms;
   }

}

?>

Adpca_custom Module Documentation
=================================

Background
----------

Due to the restrictions in Civicrm it has been necessary to write a custom Drupal module to enhance Civicrm in the following area(s):
Membership contribution (profile) defaults
The source code as well as being on the ADPCA site is stored on git hub here:
https://github.com/GordonFern/adpca_custom.git

Membership Contribution Civicrm Customisations

Override defaults
==================

Problem description:  
--------------------
We need a mechanism to change the way fields default and whether they are required in civicrm membership 
contribution pages (+profile pages) depending on the membership type the user has chosen.

Approach: 
---------
A Drupal basic page has been created “Membership Sign Up / Renewal” which contains some verbiage about 
the different membership types and has separate links to Civicrm contribution pages for 
the different membership types eg. “Individual, Student, Institutional, Supporting, Journal Subscription”
An individual Civicrm profile page has been created for each of these contribution pages.  The profile 
specifies which fields to display and whether they are mandatory or not.

Custom code has been added to catch the hook_civicrm_buildForm hook in this custom module.  At a high level 
it:
a) Checks to see if the page is a contribution pages (ignores all others)
Using the contribution page id, 

b) Checks to see if it knows about this page ADPCAConstants::getForms() (in include/config.inc) 
(if not known it ignores it)

c) Checks If ADPCA_CUSTOM_CONFIG_PATH/<contrib_name>.defaults file exists (if not it ignores it). 
<contrib_name> is looked up in step b. (APDCA_CUSTOM_CONFIG_PATH is set to 
$HOME/public_html/adpca.rutlige.com/sites/default/files/adpca_custom)

d) Goes through the <contrib_name>.defaults file which contains a number of rows <field_name>=<value> for each field found the default for this value is set based on the data in this file.  (NB. The file shouldn’t have a blank line at the end).  You should use friendly names provided in in ADPCAConstants.getFields() which will be mapped against unfriendly names such as custom_5.

Extending the capability
-------------------------

Further membership types

a) Create appropriate contribution page in Civicrm
b) Create appropriate profile in Civicrm
c) Edit sites/all/modules/adpca_custom/include/config.inc and add the new contribution page 
to the $cont_forms hash.  (NB. The ID is the id that Civicrm knows the contribution page by.

Further fields / custom fields

a) Update the profiles in Civicrm as appropriate.
b) Open the contribution page in the browser and look at the source to establish the name the field is 
known by Edit sites/all/modules/adpca_custom/include/config.inc and add the new field to the $fields hash
Edit the ADPCA_CUSTOM_CONFIG_PATH/<contrib_name>.defaults files as appropriate specify any new 
default overrides.  

The format is
do_not_email=0
do_not_mail=1
etc

Current Forms
-------------
ID	Form Name (Contribution Page pseudo name)
3	membership_individual
4	membership_student
5	membership_institutional
6	membership_supporting
7	membership_journal

Current Fields
--------------
Friend name (use in defaults file)		System Name
title						prefix_id
first_name					first_name
middle_name					middle_name
last_name					last_name
street_address					street_address-Primary
address_1					supplemental_address_1-Primary
address_2					supplemental_address_2-Primary
city						city-Primary
postal_code					postal_code-Primary
country						country-Primary
state						state_province-Primary
directory_view					custom_1
suppress_mail_address				custom_4
do_not_send_journal				custom_5
send_hard_copy_newsletter			custom_6
do_not_email					do_not_email
do_not_mail					do_not_mail
couple_membership_partner			custom_7
school_college_name				custom_8
graduation_date					custom_9


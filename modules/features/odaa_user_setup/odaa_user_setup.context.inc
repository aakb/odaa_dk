<?php
/**
 * @file
 * odaa_user_setup.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function odaa_user_setup_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'logged_in_user';
  $context->description = 'User login information';
  $context->tag = 'User';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
        'editor' => 'editor',
        'webmaster' => 'webmaster',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'heartbeat-useractivity' => array(
          'module' => 'heartbeat',
          'delta' => 'useractivity',
          'region' => 'content',
          'weight' => '-10',
        ),
        'heartbeat-nodeactivity' => array(
          'module' => 'heartbeat',
          'delta' => 'nodeactivity',
          'region' => 'content',
          'weight' => '-9',
        ),
        'menu-menu-user-accounting' => array(
          'module' => 'menu',
          'delta' => 'menu-user-accounting',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'menu-menu-user-content' => array(
          'module' => 'menu',
          'delta' => 'menu-user-content',
          'region' => 'secondary_content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  t('User login information');
  $export['logged_in_user'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user';
  $context->description = 'User login information (not logged in)';
  $context->tag = 'User';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/register' => 'user/register',
        'user/password' => 'user/password',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodespotbox-18' => array(
          'module' => 'nodespotbox',
          'delta' => '18',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  t('User login information (not logged in)');
  $export['user'] = $context;

  return $export;
}
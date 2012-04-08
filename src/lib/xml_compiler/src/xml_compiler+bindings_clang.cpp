#include "pqrs/xml_compiler.hpp"
#include "pqrs/xml_compiler_bindings_clang.h"

// ------------------------------------------------------------
int
pqrs_xml_compiler_initialize(pqrs_xml_compiler** out,
                             const char* system_xml_directory,
                             const char* private_xml_directory)
{
  if (! out) return -1;
  // return if already initialized.
  if (*out) return -1;

  *out = reinterpret_cast<pqrs_xml_compiler*>(new pqrs::xml_compiler(system_xml_directory, private_xml_directory));

  return 0;
}

void
pqrs_xml_compiler_terminate(pqrs_xml_compiler** out)
{
  if (out && *out) {
    delete reinterpret_cast<pqrs::xml_compiler*>(*out);
    *out = NULL;
  }
}

// ------------------------------------------------------------
void
pqrs_xml_compiler_reload(pqrs_xml_compiler* p)
{
  pqrs::xml_compiler* xml_compiler = reinterpret_cast<pqrs::xml_compiler*>(p);
  if (! xml_compiler) return;

  xml_compiler->reload();
}

// ------------------------------------------------------------
const char*
pqrs_xml_compiler_get_error_message(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return NULL;

  return (xml_compiler->get_error_message()).c_str();
}

size_t
pqrs_xml_compiler_get_error_count(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return 0;

  return xml_compiler->get_error_count();
}

// ------------------------------------------------------------
uint32_t
pqrs_xml_compiler_get_symbol_map_value(const pqrs_xml_compiler* p, const char* name)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return 0;

  auto v = xml_compiler->get_symbol_map_value(name);
  if (! v) return 0;

  return *v;
}

const char*
pqrs_xml_compiler_get_identifier(const pqrs_xml_compiler* p, int config_index)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return NULL;

  auto v = xml_compiler->get_identifier(config_index);
  if (! v) return NULL;

  return v->c_str();
}

uint32_t
pqrs_xml_compiler_get_appid(const pqrs_xml_compiler* p, const char* application_identifier)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return 0;

  return xml_compiler->get_appid(application_identifier);
}

// ------------------------------------------------------------
const uint32_t*
pqrs_xml_compiler_get_remapclasses_initialize_vector_data(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return NULL;

  auto v = (xml_compiler->get_remapclasses_initialize_vector()).get();
  return &(v[0]);
}

size_t
pqrs_xml_compiler_get_remapclasses_initialize_vector_size(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return 0;

  auto v = (xml_compiler->get_remapclasses_initialize_vector()).get();
  return v.size();
}

// ------------------------------------------------------------
const pqrs_xml_compiler_preferences_checkbox_node_tree*
pqrs_xml_compiler_get_preferences_checkbox_node_tree_root(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return NULL;

  return reinterpret_cast<const pqrs_xml_compiler_preferences_checkbox_node_tree*>(&(xml_compiler->get_preferences_checkbox_node_tree()));
}

static const pqrs::xml_compiler::preferences_node_tree<pqrs::xml_compiler::preferences_checkbox_node>*
cast_to_preferences_checkbox_node_tree(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  return reinterpret_cast<const pqrs::xml_compiler::preferences_node_tree<pqrs::xml_compiler::preferences_checkbox_node>*>(p);
}

size_t
pqrs_xml_compiler_get_preferences_checkbox_node_tree_children_count(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return 0;

  auto children = node_tree->get_children();
  if (! children) return 0;

  return children->size();
}

const pqrs_xml_compiler_preferences_checkbox_node_tree*
pqrs_xml_compiler_get_preferences_checkbox_node_tree_child(const pqrs_xml_compiler_preferences_checkbox_node_tree* p,
                                                           size_t index)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return NULL;

  auto children = node_tree->get_children();
  if (! children) return NULL;
  if (index >= children->size()) return NULL;

  auto child = (*children)[index];
  return reinterpret_cast<pqrs_xml_compiler_preferences_checkbox_node_tree*>(child.get());
}

const char*
pqrs_xml_compiler_get_preferences_checkbox_node_tree_name(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return NULL;

  return (node_tree->get_node()).get_name().c_str();
}

int
pqrs_xml_compiler_get_preferences_checkbox_node_tree_name_line_count(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return 0;

  return (node_tree->get_node()).get_name_line_count();
}

const char*
pqrs_xml_compiler_get_preferences_checkbox_node_tree_name_for_filter(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return NULL;

  return (node_tree->get_node()).get_name_for_filter().c_str();
}

const char*
pqrs_xml_compiler_get_preferences_checkbox_node_tree_identifier(const pqrs_xml_compiler_preferences_checkbox_node_tree* p)
{
  auto node_tree = cast_to_preferences_checkbox_node_tree(p);
  if (! node_tree) return NULL;

  auto identifier = (node_tree->get_node()).get_identifier();
  if (identifier.empty()) return NULL;

  return identifier.c_str();
}

// ------------------------------------------------------------
const pqrs_xml_compiler_preferences_number_node_tree*
pqrs_xml_compiler_get_preferences_number_node_tree_root(const pqrs_xml_compiler* p)
{
  const pqrs::xml_compiler* xml_compiler = reinterpret_cast<const pqrs::xml_compiler*>(p);
  if (! xml_compiler) return NULL;

  return reinterpret_cast<const pqrs_xml_compiler_preferences_number_node_tree*>(&(xml_compiler->get_preferences_number_node_tree()));
}

static const pqrs::xml_compiler::preferences_node_tree<pqrs::xml_compiler::preferences_number_node>*
cast_to_preferences_number_node_tree(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  return reinterpret_cast<const pqrs::xml_compiler::preferences_node_tree<pqrs::xml_compiler::preferences_number_node>*>(p);
}

size_t
pqrs_xml_compiler_get_preferences_number_node_tree_children_count(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return 0;

  auto children = node_tree->get_children();
  if (! children) return 0;

  return children->size();
}

const pqrs_xml_compiler_preferences_number_node_tree*
pqrs_xml_compiler_get_preferences_number_node_tree_child(const pqrs_xml_compiler_preferences_number_node_tree* p,
                                                         size_t index)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return NULL;

  auto children = node_tree->get_children();
  if (! children) return NULL;
  if (index >= children->size()) return NULL;

  auto child = (*children)[index];
  return reinterpret_cast<pqrs_xml_compiler_preferences_number_node_tree*>(child.get());
}

const char*
pqrs_xml_compiler_get_preferences_number_node_tree_name(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return NULL;

  return (node_tree->get_node()).get_name().c_str();
}

int
pqrs_xml_compiler_get_preferences_number_node_tree_name_line_count(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return 0;

  return (node_tree->get_node()).get_name_line_count();
}

const char*
pqrs_xml_compiler_get_preferences_number_node_tree_identifier(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return NULL;

  auto identifier = (node_tree->get_node()).get_identifier();
  if (identifier.empty()) return NULL;

  return identifier.c_str();
}

int
pqrs_xml_compiler_get_preferences_number_node_tree_default_value(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return 0;

  return (node_tree->get_node()).get_default_value();
}

int
pqrs_xml_compiler_get_preferences_number_node_tree_step(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return 0;

  return (node_tree->get_node()).get_step();
}

const char*
pqrs_xml_compiler_get_preferences_number_node_tree_base_unit(const pqrs_xml_compiler_preferences_number_node_tree* p)
{
  auto node_tree = cast_to_preferences_number_node_tree(p);
  if (! node_tree) return NULL;

  auto base_unit = (node_tree->get_node()).get_base_unit();
  if (base_unit.empty()) return NULL;

  return base_unit.c_str();
}